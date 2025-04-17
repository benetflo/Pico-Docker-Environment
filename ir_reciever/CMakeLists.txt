cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(ir_test C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

pico_generate_pio_header(ir_reciever ${CMAKE_CURRENT_LIST_DIR}/ir_reciever.pio)

add_subdirectory(src)

