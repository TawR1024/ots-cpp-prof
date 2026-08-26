cmake_minimum_required(VERSION 3.31)

project(hw3-custom-allocator VERSION 3.0.0 LANGUAGES CXX)

if(PACKAGE_VERSION)
  set(CPACK_PACKAGE_VERSION "${PACKAGE_VERSION}")
else()
  set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
endif()

message(STATUS "Package version: ${CPACK_PACKAGE_VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(custom_allocator custom_allocator/custom_allocator.cpp)
add_library(factorial tools/factorial.cpp)

add_executable(hw3-custom-allocator main.cpp)
target_link_libraries(hw3-custom-allocator PRIVATE custom_allocator factorial)
install(TARGETS hw3-custom-allocator RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
if(NOT CPACK_DEBIAN_PACKAGE_ARCHITECTURE)
  execute_process(
    COMMAND dpkg --print-architecture
    OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE
    OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()
set(CPACK_PACKAGE_CONTACT ilya.kulakov.4308@gmail.com)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER
    "Ilya Kulakov <ilya.kulakov.4308@gmail.com>")
include(CPack)

option(WITH_GTEST "Build GTest-based tests" OFF)

if(WITH_GTEST)
  find_package(GTest CONFIG)
  if(GTest_FOUND)
    enable_testing()
    include(GoogleTest)

    add_executable(custom_allocator_test custom_allocator/custom_allocator_test.cpp)
    target_link_libraries(custom_allocator_test custom_allocator GTest::gtest_main
                          GTest::gtest)
    gtest_discover_tests(custom_allocator_test)
  else()
    message(WARNING "GTest not found — tests will not be built")
  endif()
endif()