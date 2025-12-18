cmake_minimum_required(VERSION 3.20)
project(gym-class)

set(CMAKE_CXX_STANDARD 17)

set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)

add_subdirectory(external/SFML)

file(GLOB CORE_SRC
    src/core/lists/*.cpp
    src/core/models/*.cpp
    src/core/service/*.cpp
    src/core/view/*.cpp
)

add_executable(${PROJECT_NAME}
    ${CORE_SRC}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} sfml-main)

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sfml-graphics>
        $<TARGET_FILE:sfml-window>
        $<TARGET_FILE:sfml-system>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying SFML DLLs to executable directory..."
    )
endif()

if(UNIX AND NOT APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "$ORIGIN")
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
    COMMENT "Copying assets to executable directory..."
)