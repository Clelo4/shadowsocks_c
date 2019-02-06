//
// Created by jack on 19-1-26.
//

#ifndef SHADOWSOCKS_C_EVENTLOOP_H
#define SHADOWSOCKS_C_EVENTLOOP_H

#include "shell.h"
#include <time.h>
#include <signal.h>

#ifndef SS_POLL_NULL
#define SS_POLL_NULL 0x00
#endif

#ifndef SS_POLL_IN
#define SS_POLL_IN 0x01
#endif

#ifndef SS_POLL_OUT
#define SS_POLL_OUT 0x04
#endif

#ifndef SS_POLL_ERR
#define SS_POLL_ERR 0x08
#endif

#ifndef SS_POLL_HUP
#define SS_POLL_HUP 0x10
#endif

#ifndef SS_POLL_NVAL
#define SS_POLL_NVAL 0x20
#endif

// we check timeouts every TIMEOUT_PRECISION seconds
#define TIMEOUT_PRECISION 10

struct ss_eventLoop {
    void (*_impl)(); /* I/O Multiplexing Function */
    void (* add)(struct ss_eventLoop *this, FILE *stream, int mode, void *handler);
    void (* poll)(struct ss_eventLoop *this, int timeout);
    void (* remove)(struct ss_eventLoop *this, FILE *stream);
    void (* add_periodic)(struct ss_eventLoop *this, void *callback);
    void (* remove_periodic)(struct ss_eventLoop *this, void *callback);
    void (* modify)(struct ss_eventLoop *this, FILE *stream, int mode);
    void (* stop)(struct ss_eventLoop *this);
    void (* run)();

    enum MODE_TYPE { EPOLL = 1, KQUEUE = 2, SELECT = 3 };
    enum MODE_TYPE model;
    int _stopping;
    int _fdmap;
    time_t _last_time;
    int _periodic_callbacks;

};

int run_event(struct ss_eventLoop *event);
//void _add(struct ss_eventLoop *this, FILE *stream, int mode, void *handler);
//void _poll(struct ss_eventLoop *this, int timeout);
//void _remove(struct ss_eventLoop *this, FILE *stream);
//void _add_periodic(struct ss_eventLoop *this, void *callback);
//void _remove_periodic(struct ss_eventLoop *this, void *callback);
//void _modify(struct ss_eventLoop *this, FILE *stream, int mode);
//void _stop(struct ss_eventLoop *this);
//void _run();

void init_ss_eventLoop(struct ss_eventLoop *loop);
void delete_ss_eventLoop(struct ss_eventLoop *loop);

#endif //SHADOWSOCKS_C_EVENTLOOP_H
