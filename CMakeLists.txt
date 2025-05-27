cmake_minimum_required(VERSION 3.20)
project(BlueParanoiaEngine)

set(CMAKE_CXX_STANDARD 20)

# Output binary to build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/libraries/SDL3
    ${PROJECT_SOURCE_DIR}/engine
)

# Add subdirectory for engine code
add_subdirectory(engine)

# Main executable
add_executable(blueparanoia main.cpp)

# Link engine static library
target_link_libraries(blueparanoia PRIVATE blueparanoia_engine)

# Link SDL3 (system-installed)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED sdl3)
target_include_directories(blueparanoia PRIVATE ${SDL3_INCLUDE_DIRS})
target_link_libraries(blueparanoia PRIVATE ${SDL3_LIBRARIES})
