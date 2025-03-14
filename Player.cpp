#include "Player.h"
#include <SDL2/SDL_image.h>
#include <iostream>


const float JUMP_FORCE = -15.0f;
const float SPEED = 1.0f;
const float MAX_FALL_SPEED = 5.0f;
const float SCREEN_WIDTH = 730.0f;
const int COYOTE_TIME = 5;
const int JUMP_BUFFER = 5;
int coyoteTimeCounter = 0;
int jumpBufferCounter = 0;
float GRAVITY = 0;
int cameraX = 0;
const int LEVEL_WIDTH = 2000;


Player::Player() : velocityX(0), velocityY(0), isJumping(false), direction(1) {
    rect = {100, 40, 50, 50};
    frame = 0;
    frameDelay = 5;
    maxFrames = 8;
}

Player::~Player() {
    SDL_DestroyTexture(runTextureRight);
    SDL_DestroyTexture(runTextureLeft);
}

void Player::init(SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load("img/player_right.png");
    runTextureRight = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    tempSurface = IMG_Load("img/player_left.png");
    runTextureLeft = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    tempSurface = IMG_Load("img/jum_right.png");
    jumpTextureRight = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    tempSurface = IMG_Load("img/jum_left.png");
    jumpTextureLeft = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    frame = 0;
    frameDelay = 5;
    maxFrames = 8;
    direction = 1;
}

void Player::handleEvent(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                velocityX = -SPEED;
                direction = -1;
                break;
            case SDLK_RIGHT:
                velocityX = SPEED;
                direction = 1;
                break;
            case SDLK_UP:
                if (!isJumping) {
                    velocityY = JUMP_FORCE;
                    isJumping = true;
                }
                break;
        }
    }
    else if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT) {
            velocityX = 0;
        }
    }
}

void Player::update() {
    rect.x += velocityX;
    rect.y += velocityY;

    if (rect.x < 0) rect.x = 0;
    if (rect.x + rect.w > SCREEN_WIDTH) rect.x = SCREEN_WIDTH - rect.w;

    // Áp dụng trọng lực
    velocityY += 1;  // Khi đi lên, giảm tốc từ từ
    if (MAX_FALL_SPEED < velocityY)
        velocityY = MAX_FALL_SPEED;

    // Chạm đất thì dừng rơi
    if (rect.y >= 300) {
        rect.y = 300;
        isJumping = false;
        velocityY = 0;
    }

    cameraX = rect.x - SCREEN_WIDTH / 2;
    if (cameraX < 0) cameraX = 0;
    if (cameraX > LEVEL_WIDTH - SCREEN_WIDTH) cameraX = LEVEL_WIDTH - SCREEN_WIDTH;

    if (velocityX != 0) {
        frameDelay--;
        if (frameDelay <= 0) {
            frame = (frame + 1) % maxFrames;
            frameDelay = 5;
        }
    } else {
        frame = 0;
    }
}

void Player::render(SDL_Renderer* renderer) {
    SDL_Texture* currentTexture;
    if (isJumping) {
        currentTexture = (direction == 1) ? jumpTextureRight : jumpTextureLeft;
    } else {
        currentTexture = (direction == 1) ? runTextureRight : runTextureLeft;
    }

    SDL_Rect srcRect = { frame * 60, 0, 60, 60 };
    SDL_RenderCopy(renderer, currentTexture, &srcRect, &rect);
}


