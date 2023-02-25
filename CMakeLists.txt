cmake_minimum_required(VERSION 3.20.0)
project(Hello)
# add_executable(Hello main.cpp)

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)