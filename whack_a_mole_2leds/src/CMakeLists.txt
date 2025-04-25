add_executable(${PROJECT_NAME} main.c)

pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
	pico_stdlib
	pico_rand
	hardware_gpio
	pico_multicore
)
