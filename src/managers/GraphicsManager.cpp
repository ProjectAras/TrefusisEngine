//
// Created by elsa on 13.04.2020.
//

#include "GraphicsManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>


void GraphicsManager::drawToScreen(std::string filePath) {
    SDL_Texture* newTexture;
    SDL_Surface* loadSurface = IMG_Load(filePath.c_str());
    if (loadSurface == NULL) {
        printf("Unable to load the image %s, ERROR: ", filePath.c_str(), IMG_GetError);
    }
    newTexture = SDL_CreateTextureFromSurface(this->gameRenderer, loadSurface);
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

void GraphicsManager::close() {
    SDL_DestroyRenderer(this->gameRenderer);
    SDL_DestroyWindow(this->gameWindow);
    SDL_Quit();
}