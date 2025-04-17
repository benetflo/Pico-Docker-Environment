add_executable(${PROJECT_NAME} main.c ir_reciever.c)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

target_link_libraries(${PROJECT_NAME}
	pico_stdlib
	hardware_pio
	hardware_gpio
)

pico_add_extra_outputs(${PROJECT_NAME})

