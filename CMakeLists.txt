cmake_minimum_required(VERSION 2.8.11)

project(DummyEncription)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE dummyEncription.cc Matrix3x3.cpp File.cc Cryptor.cc)

if(WIN32)
    set(SOURCE ${SOURCE} XGetopt.cpp)
endif()

add_executable (dummyEncription ${SOURCE})