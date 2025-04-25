cmake_minimum_required(VERSION 3.13)
set(PICO_BOARD pico_w)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(motortest LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

pico_sdk_init()

add_executable(${PROJECT_NAME} main.c)

pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
	pico_stdlib
	pico_multicore
	hardware_gpio
)
