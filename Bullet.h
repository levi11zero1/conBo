#ifndef BULLET_H
#define BULLET_H
#include <SDL2/SDL.h>
#include "constants.h"

class Bullet {
public:
    int x, y;
    int dx, dy;
    int speed = 5;
    SDL_Texture* texture;

    Bullet(int startX, int startY, int directionX, int directionY,SDL_Renderer* renderer);
};

#endif
