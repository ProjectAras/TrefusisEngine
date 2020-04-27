set(manager_SOURCES GameManager.cpp GameManager.h GraphicsManager.cpp GraphicsManager.h
        SaveManager.cpp SaveManager.h TimeManager.cpp TimeManager.h Level.cpp Level.h)
add_library(managers ${manager_SOURCES})