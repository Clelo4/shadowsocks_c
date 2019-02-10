//
// Created by jack on 19-1-26.
//

#include "eventloop.h"



void try_cipher(const char *key, int method) {
    enum MODE_TYPE model = SELECT;
}

int __poll(struct ss_eventLoop *self, int timeout) {
    self->fds = malloc(sizeof(struct pollfd) * self->_fdmap.num); /* fds must be freed */
    nfds_t nfds = self->_fdmap.num;
    fd_handler *fd_handler_temp = self->_fdmap.first_fd_handler;
    for (int i = 0; i < nfds; i++) {
        self->fds[i].fd = fd_handler_temp->fd;
        self->fds[i].events = fd_handler_temp->mode;
        fd_handler_temp = fd_handler_temp->next;
    }
    int ret = poll(self->fds, self->_fdmap.num, TIMEOUT_PRECISION);
    return ret;
}

void __impl(struct ss_eventLoop *self) {
}

void _add(struct ss_eventLoop *self, int fd, int mode, void *handler) {
    fd_handler temp;
    temp.enable = 1;
    temp.mode = mode;
    temp.handler = handler;
    temp._periodic_callbacks = NULL;
    self->_fdmap.set(&self->_fdmap, fd, temp);
}

void _remove(struct ss_eventLoop *self, int fd) {
    self->_fdmap.delete(&self->_fdmap, fd);
}

void _add_periodic(struct ss_eventLoop *self, int fd, void *callback) {
    self->_fdmap._set_periodic(&self->_fdmap, fd, callback);
}

void _remove_periodic(struct ss_eventLoop *self, int fd, void *callback) {
    self->_fdmap._remove_periodic(&self->_fdmap, fd);
}

void _modify(struct ss_eventLoop *self, int fd, int mode) {
    self->_fdmap.modify(&self->_fdmap, fd, mode);
}

void _stop(struct ss_eventLoop *self) {
    self->_stopping = 1;
}


int _run(struct ss_eventLoop *self) {
    int asap = 0;
    int events_num = 0;
    int errno_temp = 0;
    long ms;                   // Milliseconds
    time_t s;                  // Seconds;
    struct timespec spec;

    while (!self->_stopping) {
        events_num = self->_poll(self, TIMEOUT_PRECISION);
        if (events_num == -1) {
            errno_temp = errno;
            if (errno_temp == EINTR) {
                log_debug(EINTR, "");
                asap = 1;
            }
            else if (errno_temp == EPIPE) {
                log_debug(EPIPE, "");
                asap = 1;
            }
            else {
                log_error(0, "poll: error");
            }
        } else {
            int fd;
            for (int i = 0; i < self->_fdmap.num; i++) {
                if (self->fds[i].revents) {
                    fd = self->fds[i].fd;
//                    self->_fdmap.fd_map_array[fd].fd_handler_ptr->handler->handle_event(fd, self->fds[i].revents);
                }
            }
        }
        free(self->fds);    /* free memory which is malloced in _poll function */
        clock_gettime(CLOCK_REALTIME, &spec);
        s = spec.tv_sec;
        ms = round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds.
        ms = s * 1000 + ms;
        if (asap || (ms - self->_last_time) >= TIMEOUT_PRECISION) {
            fd_handler *fd_handler_temp = self->_fdmap.first_fd_handler;
            while (fd_handler_temp) {
                fd_handler_temp->_periodic_callbacks();
                fd_handler_temp = fd_handler_temp->next;
            }
        }
        self->_last_time = ms;
    }
}

void init_ss_eventLoop(struct ss_eventLoop *loop) {
    if (loop == NULL) return ;
    loop->_impl = &__impl;
    loop->add = &_add;
    loop->_poll = &__poll;
    loop->remove = &_remove;
    loop->add_periodic = &_add_periodic;
    loop->remove_periodic = &_remove_periodic;
    loop->modify = &_modify;
    loop->stop = &_stop;
    loop->run = &_run;

    loop->_stopping = 0;
    init_fd_map(&loop->_fdmap);
}

void delete_ss_eventLoop(struct ss_eventLoop *loop) {
    delete_fd_map(&loop->_fdmap);
}