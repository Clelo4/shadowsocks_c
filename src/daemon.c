//
// Created by jack on 19-1-28.
//

#include <signal.h>
#include <syslog.h>
#include <fcntl.h>
#include "daemon.h"
#include <stdlib.h>
#include <sys/file.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
#include <unistd.h>
#include <limits.h>

#define MAXFD 64
#define BUF_SIZE 100

int daemon_proc;

int daemon_exec(struct ss_config *config) {
    if (config == NULL) return -1;
    if (!config->daemon) return 0;
#ifndef __unix__
    fprintf(stderr, "daemon mode is only supported on Unix");
    exit(EXIT_FAILURE);
#endif
    const char *pid_file = config->pid_file;
    const char *log_file = config->log_file;
    if (config->daemon == START) {
        daemon_start(pid_file, log_file);
    } else if (config->daemon == STOP) {
        daemon_stop(pid_file, log_file);
        exit(0);
    } else if (config->daemon == RESTART) {
        daemon_stop(pid_file, log_file);
        daemon_start(pid_file, log_file);
    } else {
        fprintf(stderr, "Unsupported daemon command");
        return -1;
    }
    return 0;
}

void daemon_set_user(const char *user)
{
    if (user == NULL) return ;
    struct passwd pwd;
    struct passwd *result;
    char *buf;
    size_t bufsize;
    int s;

    uid_t pw_uid;
    gid_t pw_gid;

    uid_t cur_uid;
    struct group *groupStruct;
    int ngroups, retCode;
    int numgroups_max = NGROUPS_MAX;
    gid_t groupList[numgroups_max];

    bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
    buf = malloc(bufsize);

    // get user info
    s = getpwnam_r(user, &pwd, buf, bufsize, &result);
    if (result == NULL) {
        if (s == 0) {
            printf("User %s not found\n", user);
        } else {
            errno = s;
            perror("getpwnam_r");
        }
        free(buf);
        exit(EXIT_FAILURE);
    }
    pw_uid = pwd.pw_uid;
    pw_gid = pwd.pw_gid;
    free(buf);

    cur_uid = getuid();
    if (cur_uid == pw_uid) return;
    if (cur_uid != 0) {
        fprintf(stderr, "can not set user as noroot user");
    }

    ngroups = numgroups_max;
    retCode = getgrouplist(user, pw_gid, groupList, &ngroups);
    if (retCode != -1) {
        if (retCode == ngroups && retCode != 0) {
            setgroups(retCode, groupList);
        }
    }

    setgid(pw_gid);
    setuid(pw_uid);
}

void daemon_stop(const char *pid_file, const char *log_file) {
    char buf[BUF_SIZE];
    FILE *fp;
    char *start = buf;
    int count = 0;
    int pid;

    fp = fopen(pid_file, "r");

    if (fp == NULL) exit(EXIT_FAILURE);
    fread(buf, sizeof(buf), 1, fp);
    fclose(fp);

    while (start[count] != NULL && count < sizeof(buf)) {
        if (start[count] == '\n') {
            start[count] == 0;
            break;
        }
        start += 1;
    }

    pid = atoi(buf);
    if (kill(pid, SIGTERM) == -1) {
        fprintf(stderr, "kill process %d failure, %s", pid, strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 200; i++) {
        if (kill(pid, 0) == -1) {
            if (errno == ESRCH) break;
        }
        usleep(50000);
    }

    printf("stopped");
    unlink(pid_file);
}

void daemon_start(const char *pid_file, const char *log_file) {
    pid_t pid, sid;
    int i;

    signal(SIGINT, handle_exit);
    signal(SIGTERM, handle_exit);

    if ((pid = fork()) < 0) {
        exit(EXIT_FAILURE); /* fork error. exit... */
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS); /* parent terminates */
    }

    /* Change the file mode mask */
    umask(0);

    /* Opening Logs for writing */
    // code

    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0) {
        /* Log any failure */
        exit(EXIT_FAILURE);
    }

    /* ignore SIGHUP and fork again */
    signal(SIGHUP, SIG_IGN);
    if ((pid = fork()) < 0) {
        exit(EXIT_FAILURE); // fork error
    }
    if (pid > 0) exit(EXIT_SUCCESS);

    /* Set Flag for Error Functions */
    daemon_proc = 0; /* for err_XXX() functions */

    /* Change Working Directory */
    chdir("/");

    /* Close any open descriptors */
    for (i = 0; i < MAXFD; i++) {
        close(i);
    }

    if (write_pid_file(pid_file, getpid()) == -1) {
        exit(EXIT_FAILURE);
    }

    /* Redirect stdout, and stderr to log_file */
    freopen(log_file, 'a', stderr);
    freopen(log_file, 'a', stdout);
    /* Redirect stdin to /dev/null */
    freopen("/dev/null", "r", stdin);
}

void handle_exit(int signo) {
    if (signo == SIGTERM) exit(0);
    exit(1);
}

int write_pid_file(const char *pid_file, int pid) {
    int fd;
    int flags;
    char buf[BUF_SIZE];

    fd = open(pid_file, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    // set FD_CLOEXEC
    if (flags = fcntl(fd, F_GETFD) == -1) {
        return -1;
    }
    flags |= FD_CLOEXEC;
    if ((fcntl(fd, F_SETFD, flags)) == -1)
        return -1;

    // lock pid_file
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        if (errno == EAGAIN || errno == EACCES) {
            printf("PID file '%s' is locked", pid_file);
        } else {
            fprintf(stderr, "Unable to lock PID file %s", pid_file);
            return -1;
        }
    }

    /* truncate pid_file's length to 0 */
    truncate(fd, 0);
    snprintf(buf, BUF_SIZE, "%ld\n", (long) pid);
    if (write(fd, buf, strlen(buf) != strlen(buf))) {
        return -1;
    }
    return fd;
}
