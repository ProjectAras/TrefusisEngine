//
// Created by elsa on 13.04.2020.
//

#include "GraphicsManager.h"
#include "../trefusisInternals/TrefusisConfig.h"
#include "Level.h"
#include "TimeManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>


SDL_Texture* GraphicsManager::drawToScreen(std::string filePath, bool fadeIn) {
    SDL_Texture* newTexture;
    SDL_Surface* loadSurface = IMG_Load(filePath.c_str());
    if (loadSurface == NULL) {
        printf("Unable to load the image %s, ERROR: %s", filePath.c_str(), (const char*) IMG_GetError);
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
    return newTexture;
}

SDL_Rect GraphicsManager::getSpriteSheetRectangle(envActor *ptr) {
    return SDL_Rect {TimeManager::timeConstant * TrefusisConfig::tileSize, ptr->id * TrefusisConfig::tileSize,
                     ptr->width * TrefusisConfig::tileSize, ptr->height * TrefusisConfig::tileSize};
}

GraphicsManager::GraphicsManager(int screen_width, int screen_height) {
    TTF_Init();
    this->screen_height = screen_height;
    this->screen_width = screen_width;
    this->gameWindow = SDL_CreateWindow("TrefusisEngine",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            screen_width, screen_height, SDL_WINDOW_SHOWN);
    this->gameRenderer = SDL_CreateRenderer(this->gameWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(this->gameRenderer, 255, 255, 255, 255);

}

void GraphicsManager::drawToScreen(int x, int y, SDL_Rect drawZone, SDL_Rect destinationZone, std::string fileName) {
    SDL_Surface* loadSurface = IMG_Load(fileName.c_str());
    if (loadSurface == NULL) {
        std::cout << "ERROR: \"" << fileName << "\" was not found.\n";
        std::exit(1);
    }
    SDL_SetColorKey( loadSurface, SDL_TRUE, SDL_MapRGB( loadSurface->format, 0, 0xFF, 0xFF ) );
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(this->gameRenderer, loadSurface);
    if (newTexture == NULL) {
        std::cout << "ERROR: Texture creation at drawToScreen() failed.\n";
    }
    SDL_FreeSurface(loadSurface);
    SDL_RenderCopy(this->gameRenderer, newTexture, &drawZone, &destinationZone);
    SDL_DestroyTexture(newTexture);
}

void GraphicsManager::drawToScreen(int x, int y, SDL_Rect drawZone, std::string fileName) {
    const SDL_Rect drawRect {x * TrefusisConfig::tileSize, y * TrefusisConfig::tileSize, drawZone.w, drawZone.h};
    this->drawToScreen(x, y, drawZone, drawRect, fileName);
}


void GraphicsManager::drawTextToScreen(int x, int y, SDL_Rect destZone, std::string text) {
    SDL_Color Black{0, 0, 0};
    TTF_Font* Roboto = TTF_OpenFont("../resources/roboto.ttf", 24);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Roboto, text.c_str(), Black);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(this->gameRenderer, surfaceMessage);
    SDL_RenderCopy(this->gameRenderer, Message, NULL, &destZone);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void GraphicsManager::drawPlayer(int x, int y) {
    this->drawToScreen(x, y, SDL_Rect {0, 0, 32, 32}, "../resources/images/davsan.png");
}

void GraphicsManager::drawDialogue(Dialog dialog, int x, int y) {
    if (dialog.owner.compare("player") == 0) {
        this->drawToScreen(x - 1, y - 1, SDL_Rect {0, 0, 128, 64}, SDL_Rect {(x - 3) * 64, (y - 2) * 64, 256, 128}, "../resources/images/UI_DialogBox.png");
        this->drawTextToScreen(x - 1, y - 1, SDL_Rect {(x - 2) * 52, (y - 1)* 52, 200, 50}, dialog.text);
    }
}

void GraphicsManager::drawFoilages(Player player, int renderWidth, int renderHeight, Level activeLevel) {
    int x = 0;
    for (int i = player.x- renderWidth/2; i <= player.x + renderWidth/2; i++) {
        int y = 0;
        for (int j = player.y - renderHeight/2; j<=player.y + renderWidth/2; j++) {
            if (i >= 0 && j >= 0 && i < 500 && j < 500) {
                envActor foilage = activeLevel.foilageMatrix[i][j]; // Get the foilage to draw.
                this->drawToScreen(x, y, getSpriteSheetRectangle(&foilage), TrefusisConfig::prefix + TrefusisConfig::spritesheet);
            }
            y++;
        }
        x++;
    }
}

void GraphicsManager::drawTiles(Player player, Dialog dialog, int renderWidth, int renderHeight, Level activeLevel) {
    int x = 0;
    SDL_RenderClear(this->gameRenderer);
    for (int i = player.x- renderWidth/2; i <= player.x + renderWidth/2; i++) {
        int y = 0;
        for (int j = player.y - renderHeight/2; j<=player.y + renderWidth/2; j++) {
            if (i >= 0 && j >= 0 && i < 500 && j < 500) {
                envActor tile = activeLevel.tileMatrix[i][j];  // Get the tile to draw.
                envActor foilage = activeLevel.foilageMatrix[i][j]; // Get the foilage to draw.
                this->drawToScreen(x, y, getSpriteSheetRectangle(&tile), TrefusisConfig::prefix + TrefusisConfig::spritesheet);
                if (i == player.x && j == player.y) { // Check if we are in player's location.
                    drawPlayer(x, y);
                    drawDialogue(dialog, x, y);
                }
            }
            y++;
        }
        x++;
    }
}

void GraphicsManager::drawScreen(Player player, Dialog dialog) {
    int renderWidth = TrefusisConfig::screenWidth / TrefusisConfig::tileSize;
    int renderHeight = TrefusisConfig::screenHeight / TrefusisConfig::tileSize;
    Level activeLevel = Level::activeLevel;
    drawTiles(player, dialog, renderWidth, renderHeight, activeLevel);
    drawFoilages(player, renderWidth, renderHeight, activeLevel);
    SDL_RenderPresent(this->gameRenderer);
}

void GraphicsManager::close() {
    SDL_DestroyRenderer(this->gameRenderer);
    SDL_DestroyWindow(this->gameWindow);
    TTF_Quit();
    SDL_Quit();
}

void GraphicsManager::getSpriteSheet(std::string fileName) {
    this->mainSpriteSheet =  IMG_Load(fileName.c_str());
}

