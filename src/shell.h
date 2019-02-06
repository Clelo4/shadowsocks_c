//
// Created by jack on 19-1-26.
//

#ifndef SHADOWSOCKS_C_SHELL_H
#define SHADOWSOCKS_C_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <zconf.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/stat.h>
#include "json/cJSON.h"
#include "common.h"
#include <stdint.h>
#include <arpa/inet.h>
#include <bits/socket.h>
#include "encrypt.h"

#define VERBOSE_LEVEL 5
#define USERNAME_MAX_LENGTH 32
#define version "0.1.0"

static int verbose;

enum daemon_mode {
    START = 1,
    STOP = 2,
    RESTART = 3
};

// shadowsocks config
struct ss_config {
    int is_local;
    uint16_t server_port;       /* network byte ordered */
    uint16_t local_port;        /* network byte ordered */
    struct in_addr server;
    struct in_addr  local_address;
    struct in_addr  manager_address;
    int verbose;
    int on_time_auth;
    int timeout;
    int fast_open;
    int workers;
    char user[USERNAME_MAX_LENGTH];
//    uint32_t *forbidden_ip;
    enum daemon_mode daemon;
    char pid_file[PATH_MAX];
    char log_file[PATH_MAX];
    int prefer_ipv6;
    char password[256];
    char port_password[256];
    char method[1024];
};

void print_exception();
void print_shadowsocks();
int find_config(char *resolved_path);
void check_config();
struct ss_config get_config(int is_local, int argc, char **argv);
void print_help(int is_local);
void print_local_help();
void print_server_help();
int parse_json_in_str(const char *file_path, struct ss_config *config);

#endif //SHADOWSOCKS_C_SHELL_H
