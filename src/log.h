//
// Created by jack on 19-1-31.
//

#ifndef SHADOWSOCKS_C_LOG_H
#define SHADOWSOCKS_C_LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LOG_MAX_LENGTH 1024

static void log_doit(int errnoflag, int level, const char * fmt, va_list);

void log_warn(int errnoflag, const char *fmt, ...);
void log_error(int errnoflag, const char *fmt, ...);
void log_info(int errnoflag, const char *fmt, ...);
void log_debug(int errnoflag, const char *fmt, ...);
void log_quit(int errnoflag, const char *fmt, ...);

#endif //SHADOWSOCKS_C_LOG_H
