//
// Created by elsa on 13.04.2020.
//

#include "GraphicsManager.h"
#include "../trefusisInternals/TrefusisConfig.h"
#include "MapManagerInternals/Level.h"
#include "MapManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>


SDL_Texture* GraphicsManager::drawToScreen(std::string filePath, bool fadeIn) {
    SDL_Texture* newTexture;
    SDL_Surface* loadSurface = IMG_Load(filePath.c_str());
    if (loadSurface == NULL) {
        printf("Unable to load the image %s, ERROR: ", filePath.c_str(), IMG_GetError);
    }
    newTexture = SDL_CreateTextureFromSurface(this->gameRenderer, loadSurface);
    if (fadeIn) {
        for (int i = 233; i < 255; i++) {
            SDL_SetTextureAlphaMod(newTexture, i); // Does not work.
        }
    }
    if (newTexture == NULL) {
        printf("Error with loading texture file.");
    }
    SDL_FreeSurface(loadSurface);
    SDL_RenderClear( this->gameRenderer );
    //Render texture to screen
    SDL_RenderCopy( this->gameRenderer, newTexture, NULL, NULL );
    //Update screen
    SDL_RenderPresent( this->gameRenderer );
}

GraphicsManager::GraphicsManager(int screen_width, int screen_height) {
    this->screen_height = screen_height;
    this->screen_width = screen_width;
    this->gameWindow = SDL_CreateWindow("TrefusisEngine",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            screen_width, screen_height, SDL_WINDOW_SHOWN);
    this->gameRenderer = SDL_CreateRenderer(this->gameWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(this->gameRenderer, 255, 255, 255, 255);

}

void GraphicsManager::drawToScreen(int x, int y, SDL_Rect *drawZone) {
    SDL_Rect* drawRect;
    drawRect->x = x;
    drawRect->y = y;
    drawRect->w = TrefusisConfig::tileSize;
    drawRect->h = TrefusisConfig::tileSize;
    SDL_BlitSurface(mainSpriteSheet, drawZone, this->gameSurface, drawRect);
}

/**
void GraphicsManager::drawScreen(Player player) {
    int renderWidth = TrefusisConfig::screenWidth / TrefusisConfig::tileSize;
    int renderHeight = TrefusisConfig::screenHeight / TrefusisConfig::tileSize;
    Level* activeLevel = MapManager::activeLevel;
    for (int i = player.x- renderWidth/2; i <= player.x + renderWidth/2; i++) {
        for (int j = player.y - renderHeight/2; j<=player.y + renderWidth/2; j++) {
            GraphicsManager::drawToScreen(i, j, activeLevel->tileMatrix[i][j].getTexture());
        }
    }
}
 */
void GraphicsManager::close() {
    SDL_DestroyRenderer(this->gameRenderer);
    SDL_DestroyWindow(this->gameWindow);
    SDL_Quit();
}

void GraphicsManager::getSpriteSheet(std::string fileName) {
    this->mainSpriteSheet =  IMG_Load(fileName.c_str());
}

