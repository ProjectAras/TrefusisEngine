//
// Created by elsa on 12.04.2020.
//

#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow;
SDL_Surface* gScreenSurface;
SDL_Surface* gHelloWorld;

bool Init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("An exception has occured during the initialization of the SDL: %s", SDL_GetError());
        return false;
    } else {
        gWindow = SDL_CreateWindow("TrefusisEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                    SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("An exception has occured during the creation of the game window. %s", SDL_GetError());
            return false;
        } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return true;
}

bool LoadMedia() {
    gHelloWorld = SDL_LoadBMP("data/helloworld.bmp")
}

void close() {
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_Quit();
}

int main(int argc, char* args[]){

}
