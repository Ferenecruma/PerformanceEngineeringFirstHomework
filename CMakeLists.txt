cmake_minimum_required(VERSION 3.10)

project(Homework1)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 6ea2dec23c3df14ac3b27b7d2d6bbff0cb7ba1b0) # The commit hash for 1.8.1. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_executable(program_for_profiling program_for_profiling.cpp)
target_link_libraries(program_for_profiling PRIVATE cpr::cpr)
