//
// Created by jack on 2/9/19.
//

#ifndef SHADOWSOCKS_C_FD_MAP_H
#define SHADOWSOCKS_C_FD_MAP_H

#include <stddef.h>
#include <stdlib.h>

/* select的最大描述符 */
#ifndef FD_SETSIZE
#define FD_SETSIZE 1024
#endif

typedef struct _fd_handler {
    int enable; /* 是否启用 */
    int fd;
    void (*handler)(); /* callback */
    int mode;
    void (* _periodic_callbacks)();
    struct _fd_handler *prev;
    struct _fd_handler *next;
} fd_handler;

typedef struct _map_array_element {
    fd_handler *fd_handler_ptr; /* fd_handler 指针 */
} map_array_element;

typedef struct _fd_map {
    /* The max size is FD_SETSIZE */
#define MAX_FD_LIMIT FD_SETSIZE

    map_array_element fd_map_array[MAX_FD_LIMIT];
    int num; /* the real size of fd_map_array */
    fd_handler *last_fd_handler;
    fd_handler *first_fd_handler;
    fd_handler* (* get)(struct _fd_map *map, int key);             /* get fd_handler by key */
    int (* set)(struct _fd_map *map, int key, fd_handler value);  /* set a map(key, value) */
    void (* delete)(struct _fd_map *map, int key);                  /* delete a element */
    void (* _set_periodic) (struct _fd_map *map, int key,  void *callback);
    void (* _remove_periodic) (struct _fd_map *map, int key);
    void (* modify) (struct _fd_map *map, int key, int mode);
} fd_map;

int init_fd_map(fd_map *map);
void delete_fd_map(fd_map *map);

#endif //SHADOWSOCKS_C_FD_MAP_H
