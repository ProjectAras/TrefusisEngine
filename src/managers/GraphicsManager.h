//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_GRAPHICSMANAGER_H
#define TREFUSISENGINE_GRAPHICSMANAGER_H


#include <SDL_video.h>
#include <SDL_render.h>
#include <string>
#include <vector>
#include "../objects/Player.h"
#include "../objects/EnviromentalActor.h"

class GraphicsManager {
private:
    SDL_Window* gameWindow;
    SDL_Renderer* gameRenderer;
    int screen_width;
    int screen_height;
public:
    GraphicsManager(int screen_width, int screen_height);
    void drawScreen(Player player, EnviromentalActor* enviromentalActors[], std::vector<Character> characters);
    void drawToScreen(std::string filePath);
    void drawToScreen(int x, int y, std::string filePath);
    ~GraphicsManager();
};


#endif //TREFUSISENGINE_GRAPHICSMANAGER_H
