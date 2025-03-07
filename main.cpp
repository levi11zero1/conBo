#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "funtion.h"

//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//
//SDL_Window* window = nullptr;
//SDL_Renderer* renderer = nullptr;
//SDL_Texture* background = nullptr;
//SDL_Texture* player = nullptr;
//
//bool init() {
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::cout << "SDL không thể khởi tạo! Lỗi: " << SDL_GetError() << std::endl;
//        return false;
//    }
//
//    window = SDL_CreateWindow("Contra Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    if (!window) {
//        std::cout << "Không thể tạo cửa sổ! Lỗi: " << SDL_GetError() << std::endl;
//        return false;
//    }
//
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (!renderer) {
//        std::cout << "Không thể tạo renderer! Lỗi: " << SDL_GetError() << std::endl;
//        return false;
//    }
//
//    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
//        std::cout << "SDL_image không thể khởi tạo! Lỗi: " << IMG_GetError() << std::endl;
//        return false;
//    }
//
//    return true;
//}
//
//SDL_Texture* loadTexture(const char* path) {
//    SDL_Texture* texture = nullptr;
//    SDL_Surface* loadedSurface = IMG_Load(path);
//    if (!loadedSurface) {
//        std::cout << "Không thể load ảnh " << path << "! Lỗi: " << IMG_GetError() << std::endl;
//        return nullptr;
//    }
//
//    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
//    SDL_FreeSurface(loadedSurface);
//
//    return texture;
//}
//
//void loadMedia() {
//    background = loadTexture("background.jpg");
//    player = loadTexture("character.png");
//
//    if (!background || !player) {
//        std::cout << "Lỗi load hình ảnh!" << std::endl;
//    }
//}
//
//void close() {
//    SDL_DestroyTexture(background);
//    SDL_DestroyTexture(player);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    IMG_Quit();
//    SDL_Quit();
//}
//
//void gameLoop() {
//    bool running = true;
//    SDL_Event e;
//
//    SDL_Rect playerRect = {70, 465, 50, 50}; // Vị trí nhân vật
//
//    while (running) {
//        while (SDL_PollEvent(&e)) {
//            if (e.type == SDL_QUIT) {
//                running = false;
//            }
//        }
//
//        // Vẽ nền và nhân vật
//        SDL_RenderClear(renderer);
//        SDL_RenderCopy(renderer, background, nullptr, nullptr);
//        SDL_RenderCopy(renderer, player, nullptr, &playerRect);
//        SDL_RenderPresent(renderer);
//    }
//}

int main(int argc, char* args[]) {
    if (!init()) return -1;
    loadMedia();
    gameLoop();
    close();

    return 0;
}
