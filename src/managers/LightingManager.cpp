#include "LightingManager.hpp"
#include <stdlib.h>
#include <assert.h>

LightingManager::LightingManager(int width, int height) {
    *BrightnessCells = (int *)malloc(width * height * sizeof(int)); 
}

LightingManager *LightingManager::GetLightingManager() {
    assert(LightingManager::manager != nullptr);
    return LightingManager::manager;
}

LightingManager *LightingManager::InitialiseLightingManager(int width, int height) {
    LightingManager::manager = new LightingManager(width, height);
    return GetLightingManager();
}

void LightingManager::Update(int i, int j, int modifier) {
    this->BrightnessCells[i][j] += modifier;
}