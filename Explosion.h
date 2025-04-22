
#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SDL2/SDL.h>

struct Explosion {
    int x, y;
    SDL_Texture* textures[3];
    int currentTextureIndex;
    int duration;
    bool finished;
};

#endif#pragma once
