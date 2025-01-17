cmake_minimum_required(VERSION 3.22)
project(Logger LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_library(Logger STATIC src/console_logger.cpp)
target_include_directories(Logger PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Logger)

enable_testing()
add_subdirectory(tests)