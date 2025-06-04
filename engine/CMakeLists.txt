# engine/CMakeLists.txt

# List all source files
set(ENGINE_SOURCES
    Core/App/GameLoop.cpp
    Core/App/Init.cpp
    Core/App/Iterate.cpp
    Core/App/Event.cpp
    Core/App/Quit.cpp
)

# Create a static library target
add_library(blueparanoia_engine STATIC ${ENGINE_SOURCES})

# Set include directories (relative includes are used)
target_include_directories(blueparanoia_engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link SDL3
target_link_libraries(blueparanoia_engine SDL3)
