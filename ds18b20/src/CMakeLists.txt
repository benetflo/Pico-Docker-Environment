add_executable(${PROJECT_NAME} main.c onewire.c)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    pico_hardware
)

pico_add_extra_outputs(${PROJECT_NAME})
