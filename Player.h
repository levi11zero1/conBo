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
    SDL_Texture* runTexture;
    SDL_Rect rect;
    int frame;
    int frameDelay;
    int maxFrames = 8;
    float acceleration;
    float velocityX;
    float velocityY;
    bool isJumping;
    int coyoteTimeCounter = 0;
    const int COYOTE_TIME = 10;
    int direction;
    SDL_Texture* runTextureRight;
    SDL_Texture* runTextureLeft;
    SDL_Texture* jumpTextureRight;
    SDL_Texture* jumpTextureLeft;
};

#endif

