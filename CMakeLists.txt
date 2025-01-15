cmake_minimum_required(VERSION 3.31.3)

project(portfolio LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# Specify the Emscripten toolchain if not already set
if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE
        "${CMAKE_SOURCE_DIR}/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"
        CACHE FILEPATH
        "Path to Emscripten toolchain file"
    )
endif()

# # Explicitly specify the system name
# set(CMAKE_SYSTEM_NAME Generic)
#
# # Configure the output file
# set(CMAKE_LINKER "wasm-ld")

configure_file(portfolio.h.in portfolio.h)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(portfolio ${SOURCES})

# Set the output file name to "index.wasm"
set_target_properties(portfolio PROPERTIES OUTPUT_NAME "index" SUFFIX "wasm")

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
        -Wl,--strip-all
        -Wl,--export-dynamic
        -Wl,--no-entry
        -Wl,--export=__heap_base
        -Wl,--export=ACTIVE_RENDERER_INDEX
        -Wl,--initial-memory=16908288
        -nostdlib
        -o
        "index.wasm"
)

target_include_directories(
    portfolio
    PUBLIC
        ${PROJECT_BINARY_DIR}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/thirdparty
)
