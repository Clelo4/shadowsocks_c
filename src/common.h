//
// Created by jack on 19-1-31.
//

#ifndef SHADOWSOCKS_C_COMMON_H
#define SHADOWSOCKS_C_COMMON_H

#include <ctype.h>
#include <regex.h>
#include <stdlib.h>

#define ONETIMEAUTH_BYTES 10
#define ONETIMEAUTH_CHUNK_BYTES 12
#define ONETIMEAUTH_CHUNK_DATA_LEN 2

#define ADDRTYPE_IPV4 0x01
#define ADDRTYPE_IPV6 0x04
#define ADDRTYPE_HOST 0x03
#define ADDRTYPE_AUTH 0x10
#define ADDRTYPE_MASK 0xF

int isValidIpAddress(int version, char *ipAddress);
int isValidPort(int port);
void strToUpper(char *str);
void sha1_hmac(const char *secret, const char *data);
void onetimeauth_verity(const char *_hash, const char *data, const char *key);
void onetimeauth_open(const char *data, const char *key);
void compat_ord(const char *s);
void compat_chr(const char *d);
void pack_addr(const char *address);
void parse_header(const char *data);
int match_regex(const char *pattern, const char *userString, int cflags);

#endif //SHADOWSOCKS_C_COMMON_H
