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
#include "../harlequin/DialogManager.hpp"
#include <SDL2/SDL_ttf.h>

class GraphicsManager {
private:
    SDL_Window* gameWindow;
    SDL_Renderer* gameRenderer;
    SDL_Surface* mainSpriteSheet;
    SDL_Surface* gameSurface;
    int screen_width;
    int screen_height;
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
    void drawScreen(Player player, Dialog dialog);
    /**
     * Draw a given image to the screen.
     * @param filePath File path to the image.
     * @param fadeIn Wheter or not image will be faded in.
     * @return
     */
    SDL_Texture* drawToScreen(std::string filePath, bool fadeIn);
    /**
     * Draw to screen given coordinates and a draw zone.
     * @param x X coordinate in screen.
     * @param y Y coordinate in screen
     * @param drawZone Draw zone from the image.
     */
    void drawToScreen(int x, int y, SDL_Rect drawZone, std::string fileName);
    /**
     * Draw to  screen with given coordinates and a draw zone and a destination zone.
     * @param x X coordinate in screen.
     * @param y Y coordinate in screen.
     * @param drawZone drawZone from the image.
     * @param destinationZone destination zone in the file.
     * @param fileName File name.
     */
    void drawToScreen(int x, int y, SDL_Rect drawZone, SDL_Rect destinationZone, std::string fileName);
    /**
     * Show text on screen.
     */
    void drawTextToScreen(int x, int y, SDL_Rect destZone, std::string text);
    /**
     * Close the graphics relese its resources.
     */
    void close();
};


#endif //TREFUSISENGINE_GRAPHICSMANAGER_H
