//
// Created by jack on 19-1-31.
//

#include "log.h"

void log_warn(int errnoflag, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    log_doit(errnoflag, LOG_WARNING, fmt, ap);
    va_end(ap);
    return ;
}

void log_error(int errnoflag, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    log_doit(errnoflag, LOG_ERR, fmt, ap);
    va_end(ap);
}

void log_info(int errnoflag, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    log_doit(1,LOG_INFO, fmt, ap);
    va_end(ap);
}

void log_debug(int errnoflag, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    log_doit(errnoflag, LOG_DEBUG, fmt, ap);
    va_end(ap);
}

void log_quit(int errnoflag, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    log_doit(errnoflag, LOG_ERR, fmt, ap);
    va_end(ap);
    exit(1);
}

static void log_doit(int errnoflag, int level, const char * fmt, va_list ap) {
    int n;
    char buf[LOG_MAX_LENGTH + 1];
#ifdef __USE_ISOC99
    vsnprintf(buf, LOG_MAX_LENGTH, fmt, ap);
#else
    vsprintf(buf, fmt, ap);
#endif
    n = strlen(buf);
    if (errnoflag)
        snprintf(buf + n, LOG_MAX_LENGTH - n, ": %s", strerror(errnoflag));
    strcat(buf, "\n");

    fflush(stdout);
    fputs(buf, stderr);
    fflush(stderr);

    return;
}