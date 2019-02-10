//
// Created by jack on 19-1-31.
//

#include <fcntl.h>
#include "asyncdns.h"

/**
 *
 * @param this
 * @param loop
 * @return On error, -1 is returned
 */
int _add_to_loop_dns(struct DNSResolver *this, struct ss_eventLoop* loop) {
    if (this->_loop) {
        return -1;
    }
    this->_loop = loop;
    // TODO when dns server is IPv6
    if ((this->_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        return -1;
    }
    // set no-block I/O
    int val = fcntl(this->_sock, F_GETFL, 0);
    if (val == -1) return -1;
    if (fcntl(this->_sock, F_SETFL, val | O_NONBLOCK) == -1) {
        return -1;
    }

    this->_loop->add(loop, this->_sock, POLLIN, this);
    this->_loop->add_periodic(loop, this->handle_periodic);
    return 0;
}

void _handle_periodic_dns(struct DNSResolver *this) {

}

int init_DNSResolver(struct DNSResolver *this) {
    if (!this) return;
    this->add_to_loop = &_add_to_loop_dns;
    this->handle_periodic = &_handle_periodic_dns;
    this->_loop = NULL;
}

void delete_DNSResolver(struct DNSResolver *this) {

}
