cmake_minimum_required(VERSION 3.20)
project(interpretForthLike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main interpreter.h interpreter.cpp command.h command.cpp interpreter_error.h main.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(interpretForthLike #[[interpreter.h]] interpreter.cpp #[[command.h]] command.cpp #[[interpreter_error.h]] test.cpp int_stack.h context.h)

target_link_libraries(
        interpretForthLike
        gtest_main
)
