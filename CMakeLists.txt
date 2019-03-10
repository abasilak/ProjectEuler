# Sets the minimum required version of cmake for a project.
# If the current version of CMake is lower than that required it will stop
# processing the project.
cmake_minimum_required (VERSION 2.8.3)

project (ProjectEuler)

message(STATUS "Building Project Euler Project")

### enable C++11 standard
set (CMAKE_CXX_STANDARD 11) 
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

add_definitions(-DEXECUTION_TIME_COMPUTATION)

add_subdirectory(Problem1)
add_subdirectory(Problem2)
