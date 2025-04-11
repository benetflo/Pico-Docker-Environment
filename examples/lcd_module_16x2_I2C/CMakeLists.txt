cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(lcd C CXX ASM)

pico_sdk_init()

add_subdirectory(src)
