cmake_minimum_required(VERSION 3.15)

project(Sort)

set(CMAKE_CXX_STANDARD 11)

include_directories(../Headers )

add_executable(../../Sources/InsertSort.c ${SOURCE_FILES} ../Headers/InsertSort.h)
