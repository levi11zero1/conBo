#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "Player.h"

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;

    Player player;
    bool isRunning;
    int bgX;
};

#endif
