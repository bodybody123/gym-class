cmake_minimum_required(VERSION 3.20)
project(gym-class)

set(CMAKE_CXX_STANDARD 17)

file(GLOB CORE_SRC
    src/core/lists/*.cpp
    src/core/models/*.cpp
    src/core/service/*.cpp
)

add_executable(gym-class
    ${CORE_SRC}
    src/main.cpp
)