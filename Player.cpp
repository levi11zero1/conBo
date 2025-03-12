#include "Player.h"
#include <SDL2/SDL_image.h>
#include <iostream>

const float GRAVITY = 0.6f;
const float JUMP_FORCE = -15.0f;
const float SPEED = 1.5f;
const float MAX_FALL_SPEED = 8.0f;

Player::Player() : texture(nullptr), velocityX(0), velocityY(0), isJumping(false) {
    rect = {100, 40, 50, 50}; // Vị trí ban đầu
}

Player::~Player() {
    SDL_DestroyTexture(texture);
}

void Player::init(SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load("img/player.png");
    if (!tempSurface) {
        std::cout << "Failed to load player: " << IMG_GetError() << std::endl;
        return;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

void Player::handleEvent(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                velocityX = -SPEED;
                break;
            case SDLK_RIGHT:
                velocityX = SPEED;
                break;
            case SDLK_SPACE:
                // Chỉ nhảy nếu đang trên mặt đất hoặc còn trong Coyote Time
                if (!isJumping || coyoteTimeCounter > 0) {
                    velocityY = JUMP_FORCE;
                    isJumping = true;
                    coyoteTimeCounter = 0; // Xóa Coyote Time sau khi nhảy
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

    // Áp dụng trọng lực
    if (velocityY < MAX_FALL_SPEED) {
        velocityY += GRAVITY * 0.8f;  // Nhẹ hơn để không rơi ngay lập tức
    }
    velocityY *= 0.8f;

    // Giới hạn di chuyển trong màn hình
    if (rect.x < 0) rect.x = 0;
    if (rect.x > 680) rect.x = 680;

    // Chạm đất thì dừng rơi
    if (rect.y >= 300) {
        rect.y = 300;
        isJumping = false;
        velocityY = 0;
        coyoteTimeCounter = COYOTE_TIME; // Reset Coyote Time khi chạm đất
    } else {
        coyoteTimeCounter--; // Giảm dần Coyote Time khi ở trên không
    }
    if (isJumping) {
        velocityX *= 0.95f; // Giảm tốc độ nhẹ để không bị đột ngột dừng
    }
}

void Player::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

