//
// Created by elsa on 13.04.2020.
//

#include "GraphicsManager.h"
#include <SDL.h>

void GraphicsManager::drawToScreen(std::string filePath) {
    SDL_Texture* newTexture;
    SDL_Surface* loadSurface = IMG_LOAD
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

GraphicsManager::~GraphicsManager() {
    SDL_DestroyRenderer(this->gameRenderer);
    SDL_DestroyWindow(this->gameWindow);
    SDL_Quit();
}