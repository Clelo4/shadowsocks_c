//
// Created by jack on 19-1-26.
//

#include "eventloop.h"

void try_cipher(const char *key, int method) {
    enum MODE_TYPE model = SELECT;
}

int run_event(struct ss_eventLoop *event) {

}

void _add(struct ss_eventLoop *this, FILE *stream, int mode, void *handler) {
    int fd = fileno(stream);

}

void _poll(struct ss_eventLoop *this, int timeout) {

}

void _remove(struct ss_eventLoop *this, FILE *stream) {

}

void _add_periodic(struct ss_eventLoop *this, void *callback) {

}

void _remove_periodic(struct ss_eventLoop *this, void *callback) {

}

void _modify(struct ss_eventLoop *this, FILE *stream, int mode) {

}

void _stop(struct ss_eventLoop *this) {

}

void _run() {

}

void init_ss_eventLoop(struct ss_eventLoop *loop) {
    if (loop == NULL) return ;
    loop->add = &_add;
    loop->poll = &_poll;
    loop->remove = &_remove;
    loop->add_periodic = &_add_periodic;
    loop->remove_periodic = &_remove_periodic;
    loop->modify = &_modify;
    loop->stop = &_stop;
    loop->run = &_run;


    loop->_stopping = 0;
}

void delete_ss_eventLoop(struct ss_eventLoop *loop) {
//    close(loop->_impl);
}