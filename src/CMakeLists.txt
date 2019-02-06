set(SOURCE_FILES
        shell.c shell.h
        eventloop.c eventloop.h
        tcprelay.c tcprelay.h
        udprelay.c udprelay.h
        json/cJSON.h json/cJSON.c
        encrypt.c encrypt.h
        daemon.c daemon.h
        asyncdns.c asyncdns.h
        common.c common.h
        log.c log.h)

add_executable(local local.c ${SOURCE_FILES})
add_executable(server server.c ${SOURCE_FILES})

target_link_libraries(local m)
target_link_libraries(server m)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib)
