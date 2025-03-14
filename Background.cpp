#include "Background.h"
#include <iostream>

const int SCREEN_WIDTH = 730;
const int LEVEL_WIDTH = 2000;

Background::Background() : texture(nullptr), cameraX(0) {}

Background::~Background() {
    SDL_DestroyTexture(texture);
}

void Background::init(SDL_Renderer* renderer, const char* filepath) {
    SDL_Surface* tempSurface = IMG_Load(filepath);
    if (!tempSurface) {
        std::cout << "Failed to load background: " << IMG_GetError() << std::endl;
        return;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    bgWidth = tempSurface->w;
    bgHeight = tempSurface->h;
    SDL_FreeSurface(tempSurface);
}

void Background::update(int playerX) {
    cameraX = playerX - SCREEN_WIDTH / 2;

    if (cameraX < 0) cameraX = 0;
    if (cameraX > LEVEL_WIDTH - SCREEN_WIDTH) cameraX = LEVEL_WIDTH - SCREEN_WIDTH;
}

void Background::render(SDL_Renderer* renderer) {
    SDL_Rect srcRect = { cameraX, 0, SCREEN_WIDTH, bgHeight };
    SDL_Rect destRect = { 0, 0, SCREEN_WIDTH, bgHeight };
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

