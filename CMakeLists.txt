cmake_minimum_required(VERSION 3.16.3)
project(atm)

#include the headers
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(ATMTester ${SOURCES})

