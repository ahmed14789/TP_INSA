cmake_minimum_required(VERSION 3.21)
project(TP2 C)

set(CMAKE_C_STANDARD 99)
# added -fopenmp
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -lm")
add_executable(TP2 main.c)
target_link_libraries(TP2 m)