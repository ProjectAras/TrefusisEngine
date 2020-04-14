set(manager_SOURCES GameManager.cpp GameManager.h GraphicsManager.cpp GraphicsManager.h
        SaveManager.cpp SaveManager.h TimeManager.cpp TimeManager.h MapManager.cpp MapManager.h)
add_library(managers ${manager_SOURCES})
add_subdirectory(MapManagerInternals)
target_link_libraries(managers map_manager_internals)