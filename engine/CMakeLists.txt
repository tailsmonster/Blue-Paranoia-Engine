file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(blueparanoia_engine STATIC ${ENGINE_SRC})

target_include_directories(blueparanoia_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
