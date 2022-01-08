cmake_minimum_required(VERSION 3.20)
project(interpretForthLike)

set(CMAKE_CXX_STANDARD 17)

add_executable(interpretForthLike main.cpp interpreter.h interpreter.cpp data_it.h command.h command.cpp interpreter_error.h)
