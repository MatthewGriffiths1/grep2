cmake_minimum_required(VERSION 3.5)
project(grep2)
include_directories(headers)
enable_testing()
file(GLOB SOURCES "src/*.cpp")
add_executable(grep2 ${SOURCES})
add_executable(test_cpp "test/test.cpp")

add_test(NAME test_0, COMMAND $<TARGET_FILE:test_cpp>)

