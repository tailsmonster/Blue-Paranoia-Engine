# engine/CMakeLists.txt

# Gather all .cpp files from engine (recursively)
file(GLOB_RECURSE ENGINE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(blueparanoia_engine STATIC
    ${ENGINE_SOURCES}
)

target_include_directories(blueparanoia_engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../libraries
)

target_link_libraries(blueparanoia_engine
    SDL3::SDL3
)
