cmake_minimum_required(VERSION 3.30)
project(calculator LANGUAGES C)

include_directories(
    include
)

set(SOURCES
    src/Calculator.c
    src/Execute.c
    src/Format.c
    src/Main.c
)

add_executable(calculator ${SOURCES})