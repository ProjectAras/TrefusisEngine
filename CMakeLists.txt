cmake_minimum_required(VERSION 3.15)
project(TrefusisEngine)


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${TrefusisEngine_SOURCE_DIR}/CMakeModules")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS}${SDL2_IMAGE_INCLUDE_DIRS})
add_subdirectory(src)
add_executable(TrefusisEngine src/main.cpp)
target_link_libraries(managers ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(TrefusisEngine ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(TrefusisEngine managers objects)