cmake_minimum_required(VERSION 3.31)

project(hw2-ip-filter VERSION 0.0.0 LANGUAGES CXX)

if(PACKAGE_VERSION)
    set(CPACK_PACKAGE_VERSION "${PACKAGE_VERSION}")
else()
    set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
endif()

message(STATUS "Package version: ${CPACK_PACKAGE_VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(hw2-ip-filter ip_filter.cpp)

install(TARGETS hw2-ip-filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
if(NOT CPACK_DEBIAN_PACKAGE_ARCHITECTURE)
    execute_process(
        COMMAND dpkg --print-architecture
        OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif()
set(CPACK_PACKAGE_CONTACT ilya.kulakov.43098@gmail.com)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ilya Kulakov <ilya.kulakov.43098@gmail.com>")
include(CPack)