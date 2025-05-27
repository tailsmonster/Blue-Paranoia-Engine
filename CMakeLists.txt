cmake_minimum_required(VERSION 3.16)
project(blueparanoia)

set(CMAKE_CXX_STANDARD 20)

# Use headers from your local copy
include_directories(${CMAKE_SOURCE_DIR}/external/SDL3)

add_executable(blueparanoia main.cpp)

# Link to system-wide SDL3
target_link_libraries(blueparanoia SDL3)

# Output to a local bin/ directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)