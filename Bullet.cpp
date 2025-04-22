#include "bullet.h"
#include "texture_manager.h"

//Load texture cho đạn

Bullet::Bullet(int startX, int startY, int directionX, int directionY, SDL_Renderer* renderer) {
    x = startX;
    y = startY;
    dx = directionX;
    dy = directionY;
    texture = loadTexture("asset/bullet.png", renderer);
    if (!texture) {
        SDL_Log("Không thể load texture viên đạn!");
    }
}
