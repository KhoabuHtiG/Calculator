cmake_minimum_required(VERSION 3.30)
project(calculator LANGUAGES C)

include_directories(
    include
)

set(SOURCES
    src/Calculator.c
    src/Execute.c
    src/Format.c
    src/Core.c
    src/Settings.c
)

add_library(calc SHARED ${SOURCES})
add_executable(calculator src/Main.c)
target_link_libraries(calculator calc)