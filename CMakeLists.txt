cmake_minimum_required(VERSION 3.31.3)

project(portfolio CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

configure_file(portfolio.h.in portfolio.h)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(portfolio ${SOURCES})

target_include_directories(portfolio PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/include)

target_include_directories(portfolio PUBLIC ${PROJECT_BINARY_DIR}/thirdparty)
