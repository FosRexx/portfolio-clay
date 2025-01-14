cmake_minimum_required(VERSION 3.31.3)

set(CMAKE_CXX_COMPILER "clang")

project(portfolio LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# Explicitly specify the system name
set(CMAKE_SYSTEM_NAME Generic)

# Configure the output file
set(CMAKE_LINKER "wasm-ld")

configure_file(portfolio.h.in portfolio.h)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(portfolio ${SOURCES})

# Set the output file name to "index.wasm"
set_target_properties(portfolio PROPERTIES RUNTIME_OUTPUT_NAME "index.wasm")

target_compile_options(
    portfolio
    PRIVATE
        --target=wasm32
        -DCLAY_WASM
        -mbulk-memory
        -nostdlib
        $<$<CONFIG:Debug>:-Wall
        -Werror
        -DCLAY_DEBUG
        -DDEBUG>
        $<$<CONFIG:Release>:-Os
        -UDEBUG>
)

target_link_options(
    portfolio
    PRIVATE
        -fuse-ld=lld
        -Wl,--strip-all
        -Wl,--export-dynamic
        -Wl,--no-entry
        -Wl,--export=__heap_base
        -Wl,--export=ACTIVE_RENDERER_INDEX
        -Wl,--initial-memory=6553600
        -nostdlib
        -nostartfiles
)

target_include_directories(
    portfolio
    PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(portfolio PUBLIC ${PROJECT_SOURCE_DIR}/thirdparty)
