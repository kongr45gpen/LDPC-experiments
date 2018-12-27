cmake_minimum_required(VERSION 3.13)
project(ldpc_test_opt)

set(CMAKE_CXX_STANDARD 17)

add_executable(ldpc_test_opt main.cpp tm1280.h utilities.h)
