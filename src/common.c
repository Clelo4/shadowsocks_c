//
// Created by jack on 19-1-31.
//

#include "common.h"
#include <arpa/inet.h>
#include <stdbool.h>

int isValidIpAddress(int version, char *ipAddress) {
    if (version == 4) {
        struct sockaddr_in sa;
        int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr.s_addr));
        return result != 0;
    }
    return -1;
}

int isValidPort(int port) {
    int min_port = 0;
    int max_port = 65535;
    if (port >= min_port && port <= max_port) {
        return 1;
    }
    else return 0;
}

void strToUpper(char *str) {
    char *s =  str;
    while (*s) {
        *s = toupper((unsigned char) *s);
        s++;
    }
}

int match_regex(const char *pattern, const char *userString, int cflags) {
    int result = 0;
    regex_t regex;
    int flags = cflags | REG_EXTENDED | REG_ICASE;
    int regexInit = regcomp(&regex, pattern, REG_EXTENDED);
    if (regexInit) {
        result = -1;
    } else {
        int reti = regexec( &regex, userString, 0, NULL, 0);
        if (REG_NOERROR != reti) return -1;
        else result = 0;
    }
    regfree(&regex);
    return result;
}
