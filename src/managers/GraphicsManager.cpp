//
// Created by elsa on 13.04.2020.
//

#include "GraphicsManager.h"
#include "../trefusisInternals/TrefusisConfig.h"
#include "Level.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "TimeManager.h"
#include <SDL_error.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <filesystem>
#include <unordered_map>

SDL_Texture *GraphicsManager::drawToScreen(std::string filePath, bool fadeIn) {
    SDL_Texture *newTexture;
    SDL_Surface *loadSurface = IMG_Load(filePath.c_str());
    if (loadSurface == NULL) {
        printf("Unable to load the image %s, ERROR: %s", filePath.c_str(), (const char *)IMG_GetError);
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
    SDL_RenderClear(this->gameRenderer);
    // Render texture to screen
    SDL_RenderCopy(this->gameRenderer, newTexture, NULL, NULL);
    // Update screen
    SDL_RenderPresent(this->gameRenderer);
    return newTexture;
}

SDL_Rect GraphicsManager::getSpriteSheetRectangle(envActor *ptr) {
    return SDL_Rect{TimeManager::timeConstant * TrefusisConfig::tileSize, ptr->id * TrefusisConfig::tileSize,
                    ptr->width * TrefusisConfig::tileSize, ptr->height * TrefusisConfig::tileSize};
}

void GraphicsManager::drawGlobalLighting() {
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = TrefusisConfig::screenWidth;
    rect.h = TrefusisConfig::screenHeight;
    SDL_SetRenderDrawColor(this->gameRenderer, 0, 0, 0, (255 - TimeManager::globalBrightness) * 3);
    SDL_RenderFillRect(this->gameRenderer, &rect);
    SDL_RenderPresent(this->gameRenderer);
}

GraphicsManager::GraphicsManager(int screen_width, int screen_height) {
    const auto sdlInitSuccess = SDL_Init(SDL_INIT_EVERYTHING);
    if (sdlInitSuccess != 0) {
        printf("ERR: SDL INIT FAILED %s\n", SDL_GetError());
    }
    const auto ttfInit = TTF_Init();
    if (ttfInit != 0) {
        printf("ERR: TTF INIT FAILED %s\n", SDL_GetError());
    }
    const auto imgInit = IMG_Init(IMG_INIT_PNG);
    if (imgInit == 0) {
        printf("ERR: IMG INIT FAILED %s\n", SDL_GetError());
    }
    this->screen_height = screen_height;
    this->screen_width = screen_width;
    this->gameWindow = SDL_CreateWindow("TrefusisEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width,
                                        screen_height, SDL_WINDOW_SHOWN);
    this->gameRenderer = SDL_CreateRenderer(this->gameWindow, -1, SDL_RENDERER_ACCELERATED);
    if (this->gameRenderer == NULL) {
        printf("ERROR: Renderer init failed\n%s\n", SDL_GetError());
    }
    const auto blendModeSetSuccess =
        SDL_SetRenderDrawBlendMode(this->gameRenderer,
                                   SDL_BLENDMODE_BLEND); // This allows alpha channels to work properly.
    if (blendModeSetSuccess < 0) {
        printf("ERROR: Blend mode init failed\n%s\n", SDL_GetError());
    }
    const auto renderDrawColorSuccess = SDL_SetRenderDrawColor(this->gameRenderer, 255, 255, 255, 255);
    if (renderDrawColorSuccess < 0) {
        printf("ERROR: Draw color failed\n%s\n", SDL_GetError());
    }
}

void GraphicsManager::drawToScreen(int x, int y, SDL_Rect drawZone, SDL_Rect destinationZone, std::string fileName) {
    const auto newTexture = this->getTextureFromFile(fileName);
    if (newTexture == NULL) {
        std::cout << "ERROR: Texture creation at drawToScreen() failed.\n";
    }
    SDL_RenderCopy(this->gameRenderer, newTexture, &drawZone, &destinationZone);
    SDL_DestroyTexture(newTexture);
}

void GraphicsManager::drawToScreen(Player player, int x, int y, SDL_Rect drawZone, std::string fileName) {
    const SDL_Rect drawRect{(int)std::round((x - player.x + floor(player.x)) * TrefusisConfig::tileSize),
                            (int)std::round((y - player.y + floor(player.y)) * TrefusisConfig::tileSize), drawZone.w,
                            drawZone.h};
    this->drawToScreen(x, y, drawZone, drawRect, fileName);
}

void GraphicsManager::drawTextToScreen(int x, int y, SDL_Rect destZone, std::string text) {
    SDL_Color Black{0, 0, 0};
    TTF_Font *Roboto = TTF_OpenFont("../resources/roboto.ttf", 24);
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Roboto, text.c_str(), Black);
    SDL_Texture *Message = SDL_CreateTextureFromSurface(this->gameRenderer, surfaceMessage);
    SDL_RenderCopy(this->gameRenderer, Message, NULL, &destZone);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void GraphicsManager::drawPlayer(Player player, int x, int y) {
    this->drawToScreen(player, x, y, SDL_Rect{0, 0, 64, 128}, "../resources/images/player.png");
}

void GraphicsManager::drawDialogue(Dialog dialog, int x, int y) {
    if (dialog.owner.compare("player") == 0) {
        this->drawToScreen(x - 1, y - 1, SDL_Rect{0, 0, 128, 64}, SDL_Rect{(x - 3) * 64, (y - 2) * 64, 256, 128},
                           "../resources/images/UI_DialogBox.png");
        this->drawTextToScreen(x - 1, y - 1, SDL_Rect{(x - 2) * 52, (y - 1) * 52, 200, 50}, dialog.text);
    }
}

void GraphicsManager::drawFoilages(Player player, int renderWidth, int renderHeight, Level activeLevel) {
    int x = 0;
    for (int i = player.x - renderWidth / 2; i <= player.x + renderWidth / 2; i++) {
        int y = 0;
        for (int j = player.y - renderHeight / 2; j <= player.y + renderWidth / 2; j++) {
            if (i >= 0 && j >= 0 && i < 500 && j < 500) {
                envActor foilage = activeLevel.foilageMatrix[i][j]; // Get the foilage to draw.
                this->drawTile(foilage, player, x, y);
            }
            y++;
        }
        x++;
    }
}

SDL_Texture *GraphicsManager::getTextureFromFile(std::string filePath) {
    if (this->textureCache.contains(filePath)) {
        // If already cached, get it.
        return std::get<1>(this->textureCache.at(filePath));
    }
    // If not, attempt to load the spritesheet.
    const auto surface = IMG_Load(filePath.c_str());
    if (surface == NULL) {
        printf("ERROR: Spritesheet at %s was not loaded to CPU\n%s\n", filePath.c_str(), SDL_GetError());
        this->close();
        exit(1);
    }
    const auto texture = SDL_CreateTextureFromSurface(this->gameRenderer, surface);
    if (texture == NULL) {
        printf("ERROR: Spritesheet at %s was not loaded\n", filePath.c_str());
        printf("ERROR: (cont'd) cwd is: %s\n", std::filesystem::current_path().c_str());
        printf("ERROR: SDL Reports:  %s\n", SDL_GetError());
        this->close();
        exit(1);
    }
    this->textureCache[filePath] = std::make_tuple(surface, texture);
    return texture;
}

void GraphicsManager::drawTile(envActor tile, Player player, int x, int y) {
    auto texture = this->getTextureFromFile(TrefusisConfig::prefix + TrefusisConfig::spritesheet);
    const auto spriteSheetTileRect = getSpriteSheetRectangle(&tile);
    const SDL_Rect screenRect{(int)std::round((x - player.x + floor(player.x)) * TrefusisConfig::tileSize),
                              (int)std::round((y - player.y + floor(player.y)) * TrefusisConfig::tileSize),
                              spriteSheetTileRect.w, spriteSheetTileRect.h};
    SDL_RenderCopy(this->gameRenderer, texture, &spriteSheetTileRect, &screenRect);
}

void GraphicsManager::drawTiles(Player player, Dialog dialog, int renderWidth, int renderHeight, Level activeLevel) {
    int x = 0;
    int spec_x = 0;
    int spec_y = 0;
    SDL_RenderClear(this->gameRenderer);
    for (int i = ceil(player.x) - renderWidth / 2; i <= ceil(player.x) + renderWidth / 2; i++) {
        int y = 0;
        for (int j = player.y - renderHeight / 2; j <= player.y + renderWidth / 2; j++) {
            if (i >= 0 && j >= 0 && i < 500 && j < 500) {
                envActor tile = activeLevel.tileMatrix[i][j];       // Get the tile to draw.
                envActor foilage = activeLevel.foilageMatrix[i][j]; // Get the foilage to draw.
                this->drawTile(tile, player, x, y);
            }
            y++;
        }
        x++;
    }
    drawPlayer(player, 5, 3);
    drawDialogue(dialog, spec_x, spec_y);
}

void GraphicsManager::drawScreen(Player player, Dialog dialog) {
    int renderWidth = TrefusisConfig::screenWidth / TrefusisConfig::tileSize;
    int renderHeight = TrefusisConfig::screenHeight / TrefusisConfig::tileSize;
    Level activeLevel = Level::activeLevel;
    SDL_RenderClear(this->gameRenderer);
    drawTiles(player, dialog, renderWidth, renderHeight, activeLevel);
    drawFoilages(player, renderWidth, renderHeight, activeLevel);
    SDL_RenderPresent(this->gameRenderer);
    // drawGlobalLighting();
}

GraphicsManager::~GraphicsManager() {
    for (auto &texture : this->textureCache) {
        const auto surfaceTexture = texture.second;
        SDL_FreeSurface(std::get<0>(surfaceTexture));
        SDL_DestroyTexture(std::get<1>(surfaceTexture));
    }
    this->textureCache.clear();
}

void GraphicsManager::close() {
    SDL_DestroyRenderer(this->gameRenderer);
    SDL_DestroyWindow(this->gameWindow);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void GraphicsManager::getSpriteSheet(std::string fileName) { this->mainSpriteSheet = IMG_Load(fileName.c_str()); }
