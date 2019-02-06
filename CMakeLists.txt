cmake_minimum_required(VERSION 3.13)
project(shadowsocks_c C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(CheckCSourceCompiles)
include(CheckCSourceRuns)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckTypeSize)

# Generate "config.h" from "cmake/config.h.in"
configure_file(${PROJECT_SOURCE_DIR}/cmake/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
set(CONFIG_HEADER ${CMAKE_CURRENT_BINARY_DIR}/config.h)

include_directories(BEFORE ${PROJECT_BINARY_DIR})

###############################################################################
# Subdirectories
add_subdirectory(src)
