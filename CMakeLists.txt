cmake_minimum_required(VERSION 3.31.3)

project(portfolio LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

#-------------- Adding Raylib ------------------
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)
#-----------------------------------------------

configure_file(portfolio.h.in portfolio.h)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(portfolio ${SOURCES})

target_include_directories(portfolio PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/include)

target_include_directories(portfolio PUBLIC ${PROJECT_SOURCE_DIR}/thirdparty)

# Raylib
target_link_libraries(portfolio PUBLIC raylib)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Werror -DCLAY_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
