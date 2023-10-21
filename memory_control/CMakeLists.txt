cmake_minimum_required(VERSION 3.0.0)
project(memory_control VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(memory_control main.cpp Vector.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
