#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Background {
private:
    SDL_Texture* texture;
    int bgWidth, bgHeight;
    int cameraX;

public:
    Background();
    ~Background();

    void init(SDL_Renderer* renderer, const char* filepath);
    void update(int playerX);
    void render(SDL_Renderer* renderer);
};

#endif

