cmake_minimum_required(VERSION 3.6)
project(sqlparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    README.md main.cpp Lexer.cpp Lexer.h config.h)

add_executable(sqlparser ${SOURCE_FILES})