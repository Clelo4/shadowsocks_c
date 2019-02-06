//
// Created by jack on 19-1-26.
//
#include "shell.h"
#include "eventloop.h"
#include "tcprelay.h"
#include "udprelay.h"
#include <signal.h>
#include "daemon.h"

void int_handler(int signum) {
    exit(1);
}

void close_handler(int signum) {

}

int main(int argc, char *argv[]) {
    // get Shadowsocks config
    struct ss_config config = get_config(1, argc, argv);
    // set daemon proccess
    daemon_exec(&config);
    printf("starting local at %s:%d", inet_ntoa(config.local_address), ntohs(config.local_port));

    // Shadowsocks event
    struct ss_eventLoop ss_event;

//    add_to_eventLoop(&ss_event, &handler);

    signal(SIGQUIT, close_handler);
    signal(SIGTERM, close_handler);

    signal(SIGINT, int_handler);
    daemon_set_user(config.user);

    // Loop start
    run_event(&ss_event);
}
