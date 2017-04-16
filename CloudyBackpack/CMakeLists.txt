cmake_minimum_required(VERSION 3.7)
project(CloudyBackpack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CommandBuffer.cpp CommandBuffer.h)
add_executable(CloudyBackpack ${SOURCE_FILES})