#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

class Player {
private:
    SDL_Texture* texture;
    SDL_Texture* runTexture;

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
    SDL_Rect rect;

public:
    Player();
    ~Player();

    void init(SDL_Renderer* renderer);
    void handleEvent(SDL_Event& event);
    void update();
    void render(SDL_Renderer* renderer);

    int getX() const { return rect.x; }
};

#endif

