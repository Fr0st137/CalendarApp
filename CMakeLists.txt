cmake_minimum_required(VERSION 3.28)
project(CalendarApp)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES
    header/*.h
    source/*.cpp)

add_executable(CalendarApp ${SOURCES})