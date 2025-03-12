#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

class Player {
public:
    Player();
    ~Player();

    void init(SDL_Renderer* renderer);
    void handleEvent(SDL_Event& event);
    void update();
    void render(SDL_Renderer* renderer);

private:
    SDL_Texture* texture;
    SDL_Rect rect;

    float velocityX;
    float velocityY;
    bool isJumping;
    int coyoteTimeCounter = 0;
    const int COYOTE_TIME = 10;
};

#endif

