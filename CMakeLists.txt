cmake_minimum_required(VERSION 3.16)
project(BlueParanoia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# SDL3 headers and linker flags are provided by system-wide pacman install
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED sdl3)

# Option to use SDL3 callback-style main
option(USE_SDL_CALLBACKS "Use SDL3 callback entry mode" ON)

if(USE_SDL_CALLBACKS)
    add_compile_definitions(USE_SDL_CALLBACKS)
endif()

# Add engine
add_subdirectory(engine)

# Main executable
add_executable(blueparanoia main.cpp)
target_link_libraries(blueparanoia blueparanoia_engine SDL3)

# Use SDL3's include path
target_include_directories(blueparanoia PRIVATE
    ${SDL3_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/engine
)


