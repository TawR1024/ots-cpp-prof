cmake_minimum_required(VERSION 4.2)

set(PROJECT_NAME_SAFE "hw2-ip-filter")

project(${PROJECT_NAME_SAFE})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME_SAFE} ip_filter.cpp)

set_target_properties(${PROJECT_NAME_SAFE} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)