cmake_minimum_required(VERSION 3.22)
project(BlueParanoia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Binary output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Use system-installed SDL3
find_package(SDL3 REQUIRED)

# Include engine + game code
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add the engine as a library
add_subdirectory(engine)

# Define the final executable
add_executable(blueparanoia
    main.cpp
)

target_link_libraries(blueparanoia
    blueparanoia_engine
    SDL3::SDL3
)
