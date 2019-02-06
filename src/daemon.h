//
// Created by jack on 19-1-28.
//

#ifndef SHADOWSOCKS_C_DAEMON_H
#define SHADOWSOCKS_C_DAEMON_H

#include "shell.h"

int daemon_exec(struct ss_config *config);
void daemon_set_user(const char *user);
void daemon_stop(const char *pid_file, const char *log_file);
void daemon_start(const char *pid_file, const char *log_file);
void handle_exit(int signo);
int write_pid_file(const char *pid_file, int pid);

#endif //SHADOWSOCKS_C_DAEMON_H
