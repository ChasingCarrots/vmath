cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

set(PROJECT_NAME "vmath")
project(vmath)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/inc/vmath)
add_library(vmath SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/vmath.cpp)

target_include_directories(vmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
