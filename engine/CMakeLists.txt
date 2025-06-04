# Gather all .cpp source files under engine/
file(GLOB_RECURSE ENGINE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(blueparanoia_engine STATIC
    ${ENGINE_SOURCES}
)

target_include_directories(blueparanoia_engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(blueparanoia_engine
    SDL3::SDL3
)
