cmake_minimum_required(VERSION 3.15)
project(TrefusisEngine)


set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(TrefusisEngine src/main.cpp)
add_subdirectory(src)
target_link_libraries(TrefusisEngine ${SDL2_LIBRARIES})