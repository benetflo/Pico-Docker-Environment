cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

project(Pico_ePaper_Code)
pico_sdk_init()

add_subdirectory(./lib/Config)
add_subdirectory(./lib/LCD)
add_subdirectory(./lib/Fonts)
add_subdirectory(./lib/GUI)
add_subdirectory(./lib/QMI8658)
add_subdirectory(./examples)

include_directories(./examples)
include_directories(./lib/Config)
include_directories(./lib/Fonts)
include_directories(./lib/GUI)
include_directories(./lib/LCD)
include_directories(./lib/QMI8658)

add_executable(main 
main.c
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 1)

pico_add_extra_outputs(main)

target_link_libraries(main examples LCD QMI8658 GUI Fonts Config pico_stdlib hardware_spi hardware_i2c )
