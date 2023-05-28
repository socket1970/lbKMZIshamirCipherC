cmake_minimum_required(VERSION 3.16)
project(shamirCipher C)

set(SOURCES main.c src/prime.c src/calculations.c src/crypt.c)
set(HEADERS headers/prime.h headers/calculations.h headers/crypt.h)

set(CMAKE_C_STANDARD 11)

add_executable(shamirCipher ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC headers)

target_link_libraries(${PROJECT_NAME} gmp)
