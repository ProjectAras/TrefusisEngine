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
    SDL_Surface* gameSurface;
    int screen_width;
    int screen_height;
    /**
     * Given a pointer to a vector of textures, free their memory.
     * @param textureVector Vector of textures.
     */
    void freeTextures(std::vector<SDL_Texture*> *textureVector);
    std::vector<SDL_Texture*> textures;
    /**
     * Load the spritesheet onto the RAM.
     * @return
     */
    void getSpriteSheet(std::string);
public:
    /**
     * Initialise a Graphics Manager with given sizes.
     * @param screen_width
     * @param screen_height
     */
    GraphicsManager(int screen_width, int screen_height);
    /**
     * Initialise an empty graphics manager.
     */
    GraphicsManager() : GraphicsManager(640, 480) {};
    /**
     * Given the player character render the screen.
     * @param player
     * @param enviromentalActors
     * @param characters
     */
    void drawScreen(Player player);
    SDL_Texture* drawToScreen(std::string filePath, bool fadeIn);

    SDL_Texture* drawToScreen(int x, int y, SDL_Rect drawZone);
    void close();
};


#endif //TREFUSISENGINE_GRAPHICSMANAGER_H
