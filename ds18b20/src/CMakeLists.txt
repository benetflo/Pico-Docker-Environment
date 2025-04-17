add_executable(${PROJECT_NAME} main.c onewire.c)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
