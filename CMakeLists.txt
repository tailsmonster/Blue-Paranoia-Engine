cmake_minimum_required(VERSION 3.22)
project(BlueParanoia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set build output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find SDL3 installed on the system (from pacman or system path)
find_package(SDL3 REQUIRED)

# Include engine and include folders
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries
)

# Add engine subdirectory
add_subdirectory(engine)

# Build the main executable
add_executable(blueparanoia
    main.cpp
)

# Link to our engine static lib and SDL3
target_link_libraries(blueparanoia
    blueparanoia_engine
    SDL3::SDL3
)
