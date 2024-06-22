cmake_minimum_required(VERSION 3.12.0)
project(minesweeper VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(minesweeper main.cpp)

file(GLOB SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "include/*.h")
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_sources(minesweeper PRIVATE ${SRCS} ${HDRS})
target_include_directories(minesweeper PRIVATE include)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
include_directories(assets)

target_link_libraries(minesweeper PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network) 
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

