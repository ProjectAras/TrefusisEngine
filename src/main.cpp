//
// Created by elsa on 12.04.2020.
//

#include <stdio.h>
#include "managers/GameManager.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[]){
    GameManager gm;
    while (!gm.quit) {
        gm.Update();
    }
    gm.close();
}
