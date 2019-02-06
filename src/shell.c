//
// Created by jack on 19-1-26.
//

#include "shell.h"

static int verbose = 0;

void print_exception() {
}

void print_shadowsocks() {
    printf("Shadowsocks %s", version);
}

int find_config(char *resolved_path) {
	char cwd[PATH_MAX];
	realpath("./config.json", cwd);
	if (access(cwd, F_OK) != -1) {
	    memcpy(resolved_path, cwd, strlen(cwd));
        return 0;
	} else {
        bzero(cwd, sizeof(cwd));
        realpath("../config.json", cwd);
        if (access(cwd, F_OK) != -1) {
            memcpy(resolved_path, cwd, PATH_MAX);
            return 0;
        }
        else {
            return -1;
        }
	}
}

void check_config(struct ss_config *config, int is_local) {
    if (config->daemon == STOP) return ;
    if (is_local) {
        if (config->server.s_addr == NULL) {
            print_local_help();
            exit(EXIT_FAILURE);
        }
    } else {
        if (config->server.s_addr == NULL) {
            inet_pton(AF_INET, "0.0.0.0", &config->server);
        }
        // code
    }
    if (is_local && config->password[0] == NULL) {
        print_help(is_local);
        exit(EXIT_FAILURE);
    }
    if (!is_local && config->port_password[0] == NULL && config->password[0] == NULL && config->manager_address.s_addr == NULL) {
        print_help(is_local);
        exit(EXIT_FAILURE);
    }
    if (config->local_address.s_addr == inet_addr("0.0.0.0")) {
        fprintf(stderr, "warning: local set to listen on 0.0.0.0, it\\'s not safe");
        exit(EXIT_FAILURE);
    }
    if (config->server.s_addr == inet_addr("127.0.0.1")) {
        fprintf(stderr, "warning: server set to listen on %s:%d, are you sure?' \n", inet_ntoa(config->server), ntohs(config->server_port));
    }
    if (config->timeout < 100) {
        fprintf(stdout, "warning: you timeout %d seems too short", config->timeout);
    }
    if (config->timeout > 600) {
        fprintf(stdout, "warning: you timeout %d seems too long", config->timeout);
    }
    if (config->user[0] != NULL) {
#ifdef __unix__
        fprintf(stderr, "user can be used only on Unix");
        exit(EXIT_FAILURE);
#endif
    }
    // encrypt password
    try_cipher(config->password, NULL);
}

struct ss_config get_config(int is_local, int argc, char **argv) {
    char *short_opts = malloc(sizeof(char) * 2048);
    struct option *long_options;
    int ch;
    struct ss_config config;
    char config_path[PATH_MAX];  /* config file path */
    int v_count = 0;
    char daemon_temp[8] = {0};

    bzero(&config, sizeof (struct ss_config));
    config.is_local = is_local;

    if (is_local) {
        const char *local_short_opts = "hd:s:b:p:k:l:m:c:t:vqa";
        memcpy(short_opts, local_short_opts, strlen(local_short_opts));
        const struct option long_options_temp[] = {
            {"help", no_argument, NULL, 'h'},
            {"fast-open", no_argument, NULL, 'f'},
            {"pid-file", required_argument, NULL, 'P'},
            {"log-file", required_argument, NULL, 'L'},
            {"user", required_argument, NULL, 'U'},
            {"version", no_argument, NULL, 'V'},
            {NULL, 0, NULL, 0}
        };
        long_options = malloc(sizeof(long_options_temp));
        memcpy(long_options, long_options_temp, sizeof(long_options_temp));
    } else {
        const char *server_short_opts = "hd:s:p:k:m:c:t:vqa";
        memcpy(short_opts, server_short_opts, strlen(server_short_opts));
        const struct option long_options_temp[] = {
            {"help", no_argument, NULL, 'h'},
            {"fast-open", no_argument, NULL, 'f'},
            {"pid-file", required_argument, NULL, 'P'},
            {"log-file", required_argument, NULL, 'L'},
            {"workers", required_argument, NULL, 'W'},
            {"forbidden-ip", no_argument, NULL, 'F'},
            {"user", no_argument, NULL, 'U'},
            {"manager-address", no_argument, NULL, 'M'},
            {"version", required_argument, NULL, 'V'},
            {"prefer-ipv6", required_argument, NULL, 'r'},
            {NULL, 0, NULL, 0}
        };
        long_options = malloc(sizeof(long_options_temp));
        memcpy(long_options, long_options_temp, sizeof(long_options_temp));
    }

    if (find_config(config_path) != 0) {
        fprintf(stderr, "Error: can't get config file.");
        abort();
    }
    while ((ch = getopt_long(argc, argv, short_opts, long_options, NULL)) != -1) {
        if (ch == 'c') {
            memcpy(config_path, optarg, strlen(optarg));
            optind = 1;
            break;
        }
    }

    if (config_path[0]) {
        parse_json_in_str(config_path, &config);
    }

    while ((ch = getopt_long(argc, argv, short_opts, long_options, NULL)) != -1) {
        switch (ch) {
            case 'a':
                config.on_time_auth = 1;
                break;
            case 'b':
                inet_pton(AF_INET, optarg, &config.local_address);
                break;
            case 'c':
                break;
            case 'd':
                bzero(daemon_temp, sizeof (daemon_temp));
                strncpy(daemon_temp, optarg, sizeof(daemon_temp));
                strToUpper(daemon_temp);
                if (strcmp(daemon_temp, "START") == 0) {
                    config.daemon = START;
                } else if (strcmp(daemon_temp, "STOP") == 0) {
                    config.daemon = STOP;
                } else if (strcmp(daemon_temp, "RESTART") == 0) {
                    config.daemon = RESTART;
                }
                break;
            case 'f':
                config.fast_open = 1;
                break;
            case 'h':
                print_help(is_local);
                goto EXIT;
                break;
            case 'k':
                strncpy(config.password, optarg, sizeof(config.password));
                break;
            case 'l':
                config.local_port = htons(atoi(optarg));
                break;
            case 'm':
                strncpy(config.method, optarg, sizeof(config.method));
                break;
            case 'p':
                config.server_port = htons(atoi(optarg));
                break;
            case 'q':
                v_count -= 1;
                config.verbose = v_count;
                break;
            case 'r':
                config.prefer_ipv6 = 1;
                break;
            case 's':
                inet_pton(AF_INET, optarg, &config.server);
                break;
            case 't':
                config.timeout = atoi(optarg);
                break;
            case 'v':
                v_count += 1;
                config.verbose = v_count;
                break;
            case 'F':
                // forbidden-ip
                // code
                break;
            case 'L':
                strncpy(&config.log_file, optarg, sizeof(config.log_file));
                break;
            case 'M':
                inet_pton(AF_INET, optarg, &config.manager_address);
                break;
            case 'P':
                strncpy(&config.pid_file, optarg, sizeof(config.pid_file));
                break;
            case 'U':
                strncpy(&config.user, optarg, sizeof(config.user));
                break;
            case 'V':
                print_shadowsocks();
                goto EXIT;
                break;
            case 'W':
                config.workers = atoi(optarg);
                break;
            case '?':
                break;
            default:
                break;
        }
    }

    free(short_opts);
    free(long_options);
    return config;
EXIT:
    free(short_opts);
    free(long_options);
    exit(EXIT_SUCCESS);
}

void print_help(int is_local) {
    if (is_local) {
        print_local_help();
    } else {
        print_server_help();
    }
}

void print_local_help() {
    printf("Usae: sslocal [OPTION]..."
           "Proxy options:"
           "  -c CONFIG              path to config file"
           "  -s SERVER_ADDR         server address"
           "  -p SERVER_PORT         server port, default: 8388"
           "  -b LOCAL_ADDR          local binding address, default: 127.0.0.1"
           "  -l LOCAL_PORT          local port, default: 1080"
           "  -k PASSWORD            password"
           "  -m METHOD              encryption method, default: aes-256-cfb"
           "  -t TIMEOUT             timeout in seconds, default: 300"
           "  -a ONE_TIME_AUTH       one time auth"
           "  --fast-open            use TCP_FASTOPEN, requires Linux 3.7+"
           ""
           "General options:"
           "  -h, --help             show this help message and exit"
           "  -d start/stop/restart  daemon mode"
           "  --pid-file PID_FILE    pid file for daemon mode"
           "  --log-file LOG_FILE    log file for daemon mode"
           "  --user USER            username to run as"
           "  -v, -vv                verbose mode"
           "  -q, -qq                quiet mode, only show warnings/errors"
           "  --version              show version information"
           "Online help: <https://github.com/Clelo4/shadowsocks_c>");
}

void print_server_help() {
    printf("usage: ssserver [OPTION]..."
           "Proxy options:"
           "  -c CONFIG              path to config file"
           "  -s SERVER_ADDR         server address, default: 0.0.0.0"
           "  -p SERVER_PORT         server port, default: 8388"
           "  -k PASSWORD            password"
           "  -m METHOD              encryption method, default: aes-256-cfb"
           "  -t TIMEOUT             timeout in seconds, default: 300"
           "  -a ONE_TIME_AUTH       one time auth"
           "  --fast-open            use TCP_FASTOPEN, requires Linux 3.7+"
           "  --workers WORKERS      number of workers, available on Unix/Linux"
           "  --forbidden-ip IPLIST  comma seperated IP list forbidden to connect"
           "  --manager-address ADDR optional server manager UDP address, see wiki"
           "  --prefer-ipv6          resolve ipv6 address first"
           ""
           "General options:"
           "  -h, --help             show this help message and exit"
           "  -d start/stop/restart  daemon mode"
           "  --pid-file PID_FILE    pid file for daemon mode"
           "  --log-file LOG_FILE    log file for daemon mode"
           "  --user USER            username to run as"
           "  -v, -vv                verbose mode"
           "  -q, -qq                quiet mode, only show warnings/errors"
           "  --version              show version information"
           "Online help: <https://github.com/Clelo4/shadowsocks_c>");
}

int parse_json_in_str(const char *filename, struct ss_config *config) {
    if (config == NULL) return -1;
    FILE *fp;
    struct stat filestatus;
    int file_size;
    char *file_contents;
    cJSON *json = NULL;

    if (stat(filename, &filestatus) != 0) {
        fprintf(stderr, "File %s not found\n", filename);
        return -1;
    }
    file_size = filestatus.st_size;
    file_contents = (char *)malloc(file_size);
    if (file_contents == NULL) {
        fprintf(stderr, "Memory error: unable to allocate %d bytes\n", file_size);
        free(file_contents);
        return -1;
    }

    fp = fopen(filename, "rt");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open %s\n", filename);
        fclose(fp);
        free(file_contents);
        return -1;
    }
    if (fread(file_contents, file_size, 1, fp) != 1) {
        fprintf(stderr, "Unable t read content of %s\n", filename);
        fclose(fp);
        free(file_contents);
        return -1;
    }

    fclose(fp);
    json = cJSON_Parse(file_contents);
    free(file_contents);

    cJSON *first = json->child;
    while (first != NULL) {
        const char *name = first->string;
        if (strncmp(name, "server", strlen(name)) == 0) {
            if (isValidIpAddress(4, first->valuestring)) {
                inet_pton(AF_INET, first->valuestring, &config->server);
            } else {
                fprintf(stderr, "server address error");
            }
        } else if (strncmp(name, "server_port", strlen(name)) == 0) {
            if (isValidPort(first->valueint)) {
                config->server_port = htons(first->valueint);
            } else {
                fprintf(stderr, "server port error");
            }
        } else if (strncmp(name, "local_address", strlen(name)) == 0) {
            if (isValidIpAddress(4, first->valuestring)) {
                inet_pton(AF_INET, first->valuestring, &config->local_address);
            } else {
                fprintf(stderr, "local address error");
            }
        } else if (strncmp(name, "local_port", strlen(name)) == 0) {
            if (isValidPort(first->valueint)) {
                config->local_port = htons(first->valueint);
            } else {
                fprintf(stderr, "local port error");
            }
        } else if (strncmp(name, "password", strlen(name)) == 0) {
            strncpy(config->password, first->valuestring, sizeof(config->password));
        } else if (strncmp(name, "timeout", strlen(name)) == 0) {
            config->timeout = first->valueint;
        } else if (strncmp(name, "method", strlen(name)) == 0) {
            strncpy(config->method, first->valuestring, sizeof(config->password));
        } else if (strncmp(name, "fast_open", strlen(name)) == 0) {
            if (first->type == cJSON_True) config->fast_open = 1;
            else config->fast_open = 0;
        } else if (strncmp(name, "workers", strlen(name)) == 0) {
            config->workers = first->valueint;
        } else if (strncmp(name, "prefer_ipv6", strlen(name)) == 0) {
            if (first->type == cJSON_True) config->prefer_ipv6 = 1;
            else config->prefer_ipv6 = 0;
        } else if (strcmp("port_password", name) == 0) {
            strncpy(config->port_password, first->valuestring, sizeof(config->port_password));
        }
        first = first->next;
    }

    cJSON_Delete(json);
    return 0;
}
