//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_GRAPHICSMANAGER_H
#define TREFUSISENGINE_GRAPHICSMANAGER_H


#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <vector>
#include "../objects/Player.h"
#include "../objects/EnviromentalActor.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>

class GraphicsManager {
private:
    SDL_Window* gameWindow;
    SDL_Renderer* gameRenderer;
    SDL_Surface* mainSpriteSheet;
    int screen_width;
    int screen_height;
    std::vector<SDL_Texture*> textures;
    /**
     * Load the spritesheet onto the RAM.
     * @return
     */
    void getSpriteSheet(std::string);
public:
    GraphicsManager(int screen_width, int screen_height);
    GraphicsManager() : GraphicsManager(640, 480) {};
    void drawScreen(Player player, EnviromentalActor* enviromentalActors[], std::vector<Character> characters);
    SDL_Texture* drawToScreen(std::string filePath, bool fadeIn);
    SDL_Texture* drawToScreen(int x, int y, std::string filePath);
    void close();
};


#endif //TREFUSISENGINE_GRAPHICSMANAGER_H
