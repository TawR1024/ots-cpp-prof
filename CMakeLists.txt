cmake_minimum_required(VERSION 4.2)

set(PROJECT_NAME_SAFE "default_project")

project(${PROJECT_NAME_SAFE})

add_executable(${PROJECT_NAME_SAFE} main.cpp)

set_target_properties(${ROJECT_NAME_SAFE} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)