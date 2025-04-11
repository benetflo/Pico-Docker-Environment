cmake_minimum_required(VERSION 3.13)

set(exec basic_lcd)

add_executable(${exec} main.c lcd.c)

target_include_directories(${exec} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${exec}
	pico_stdlib
	hardware_i2c
)

pico_add_extra_outputs(${exec})
