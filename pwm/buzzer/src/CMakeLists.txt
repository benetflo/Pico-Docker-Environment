add_executable(${PROJECT_NAME} main.c buzzer_melodies.c)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
	pico_stdlib
	hardware_pwm
	hardware_gpio
)
