cmake_minimum_required(VERSION 3.15)
project(TrefusisEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(TrefusisEngine src/main.cpp src/objects/Actor.cpp src/objects/Actor.h src/objects/EnviromentalActor.cpp src/objects/EnviromentalActor.h src/utility/FileReader.cpp src/utility/FileReader.h src/managers/GameManager.cpp src/managers/GameManager.h src/objects/Character.cpp src/objects/Character.h)
target_link_libraries(TrefusisEngine ${SDL2_LIBRARIES})