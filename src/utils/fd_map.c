//
// Created by jack on 2/9/19.
//

#include "fd_map.h"

fd_handler* fd_map_get(fd_map *map, int key) {
    if (!map) return NULL;
    if (map->num == 0) return NULL;
    if (key < MAX_FD_LIMIT && map->fd_map_array[key].fd_handler_ptr && map->fd_map_array[key].fd_handler_ptr->enable) {
        return map->fd_map_array[key].fd_handler_ptr;
    }
    return NULL;
}

int fd_map_set(fd_map *map, int key, fd_handler value) {
    if (!map) return -1;
    if (map->num == 0) return -1;
    if (key >= MAX_FD_LIMIT) return -1;

    fd_handler *fd_handler_ptr = malloc(sizeof(fd_handler));
    fd_handler_ptr->enable = 1;
    fd_handler_ptr->handler = value.handler;
    fd_handler_ptr->mode = value.mode;
    fd_handler_ptr->_periodic_callbacks = value.mode;
    fd_handler_ptr->next = NULL;
    fd_handler_ptr->fd = key;
    map->fd_map_array[key].fd_handler_ptr = fd_handler_ptr;
    if (map->num == 0) {
        map->first_fd_handler = fd_handler_ptr;
        map->first_fd_handler->prev = NULL;
    } else {
        map->last_fd_handler->next = fd_handler_ptr;
        fd_handler_ptr->prev = map->last_fd_handler;
    }
    map->last_fd_handler = fd_handler_ptr;
    map->num += 1;
    return 0;
}

void fd_map_delete(fd_map *map, int key) {
    fd_handler *fd_handler_ptr = NULL;
    if (!map) return;
    if (map->num == 0) return;
    if (key < MAX_FD_LIMIT && map->fd_map_array[key].fd_handler_ptr && map->fd_map_array[key].fd_handler_ptr->enable) {
        fd_handler_ptr = map->fd_map_array[key].fd_handler_ptr;
        if (fd_handler_ptr == map->first_fd_handler) {
            map->first_fd_handler = map->first_fd_handler->next;
            if (map->first_fd_handler) {
                map->first_fd_handler->prev = NULL;
            }
            else {
                map->last_fd_handler = map->first_fd_handler;
            }
        } else {
            if (fd_handler_ptr == map->last_fd_handler) map->last_fd_handler = fd_handler_ptr->prev;
            if (fd_handler_ptr->next) fd_handler_ptr->next->prev = fd_handler_ptr->prev;
            fd_handler_ptr->prev->next = fd_handler_ptr->next;
        }
        map->num -= 1;
        free(fd_handler_ptr);
    }
}

void _fd_map_set_periodic (struct _fd_map *map, int key,  void *callback) {
    if (!map) return ;
    if (map->num == 0) return;
    if (key < MAX_FD_LIMIT && map->fd_map_array[key].fd_handler_ptr && map->fd_map_array[key].fd_handler_ptr->enable) {
        map->fd_map_array[key].fd_handler_ptr->_periodic_callbacks = callback;
    }
}

void _fd_map_remove_periodic (struct _fd_map *map, int key) {
    if (!map) return ;
    if (map->num == 0) return;
    if (key < MAX_FD_LIMIT && map->fd_map_array[key].fd_handler_ptr && map->fd_map_array[key].fd_handler_ptr->enable) {
        map->fd_map_array[key].fd_handler_ptr->_periodic_callbacks = NULL;
    }
}

void _fd_map_modify (struct _fd_map *map, int key, int mode) {
    if (!map) return ;
    if (map->num == 0) return;
    if (key < MAX_FD_LIMIT && map->fd_map_array[key].fd_handler_ptr && map->fd_map_array[key].fd_handler_ptr->enable) {
        map->fd_map_array[key].fd_handler_ptr->mode = mode;
    }
}

int init_fd_map(fd_map *map) {
    if (!map) return -1;
    map->num = 0;
    map->last_fd_handler = NULL;
    map->first_fd_handler = NULL;
    map->get = &fd_map_get;
    map->set = &fd_map_set;
    map->delete = &fd_map_delete;
    map->_set_periodic = &_fd_map_set_periodic;
    map->_remove_periodic = &_fd_map_remove_periodic;
    map->modify = &_fd_map_modify;
}

void delete_fd_map(fd_map *map) {
    fd_handler *fd_handler_current = map->first_fd_handler;
    fd_handler *fd_handler_next = fd_handler_current->next;
    while (fd_handler_current) {
        free(fd_handler_current);
        fd_handler_current = fd_handler_next;
        fd_handler_next = fd_handler_current->next;
    }
    map->num = 0;
}