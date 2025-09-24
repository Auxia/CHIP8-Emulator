cmake_minimum_required(VERSION 3.15)

project(CHIP8-Emulator LANGUAGES C CXX)

set(SET_C_STANDARD 99)
set(SET_CXX_STANDARD 11)

# Enable testing
include(CTest)
enable_testing()

# Include dirs
include_directories(${PROJECT_SOURCE_DIR}/include)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Core executable
add_executable(chip8emu
src/memory.cpp
)
target_link_libraries(chip8emu ${SDL2_LIBRARIES})

# Tests
add_subdirectory(tests)
