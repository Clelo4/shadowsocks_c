//
// Created by jack on 19-1-31.
//

#ifndef SHADOWSOCKS_C_ASYNCDNS_H
#define SHADOWSOCKS_C_ASYNCDNS_H

#include "eventloop.h"

#define CACHE_SWEEP_INTERVAL 30

#define STATUS_FIRST 0
#define STATUS_SECOND 1

#define QTYPE_ANY 255
#define QTYPE_A 1
#define QTYPE_AAAA 28
#define QTYPE_CNAME 5
#define QTYPE_NS 2
#define QCLASS_IN 1

#define HOSTNAME_MAX_LENGTH 253

/*
# rfc1035
# format
# +---------------------+
# |        Header       |
# +---------------------+
# |       Question      | the question for the name server
# +---------------------+
# |        Answer       | RRs answering the question
# +---------------------+
# |      Authority      | RRs pointing toward an authority
# +---------------------+
# |      Additional     | RRs holding additional information
# +---------------------+
#
# header
#                                 1  1  1  1  1  1
#   0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
# +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
# |                      ID                       |
# +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
# |QR|   Opcode  |AA|TC|RD|RA|   Z    |   RCODE   |
# +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
# |                    QDCOUNT                    |
# +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
# |                    ANCOUNT                    |
# +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
# |                    NSCOUNT                    |
# +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
# |                    ARCOUNT                    |
# +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
 * */
void dns_build_address();
void dns_build_request();
void dns_parse_ip(int addrtype, const char *data, int length, int offset);
void dns_parse_name(const char *name, int offset);

/*
# rfc1035
# record
#                                    1  1  1  1  1  1
#      0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
#    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
#    |                                               |
#    /                                               /
#    /                      NAME                     /
#    |                                               |
#    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
#    |                      TYPE                     |
#    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
#    |                     CLASS                     |
#    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
#    |                      TTL                      |
#    |                                               |
#    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
#    |                   RDLENGTH                    |
#    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--|
#    /                     RDATA                     /
#    /                                               /
#    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
 * */
void dns_parse_record(const char *data, int offset, int question);
void dns_parse_header(const char *data);
void dns_parse_response(const char *data);
int is_valid_hostname(const char *hostname);

struct DNSResponse {
    char hostname[HOSTNAME_MAX_LENGTH];
    int questions;
    int answers;
};

struct DNSResolver {
    int (*add_to_loop)(struct DNSResolver *this, struct ss_eventLoop*);
    struct ss_eventLoop * _loop;
    int _sock;
};

int _add_to_loop_dns(struct DNSResolver *this, struct ss_eventLoop* loop);

void init_DNSResolver(struct DNSResolver *res);

#endif //SHADOWSOCKS_C_ASYNCDNS_H
