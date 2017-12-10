cmake_minimum_required(VERSION 3.8)
project(Longlong_num)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c bn_matrenok.c bn.h)
add_executable(Longlong_num ${SOURCE_FILES})
target_link_libraries(Longlong_num m)