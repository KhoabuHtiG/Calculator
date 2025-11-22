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
    src/Core.c
    src/Settings.c
)

add_executable(calculator ${SOURCES})