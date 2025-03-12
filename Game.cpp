#include "Game.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr), backgroundTexture(nullptr), isRunning(false), bgX(0) {}

Game::~Game() {}

bool Game::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL Init Failed: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Surface* tempSurface = IMG_Load("img/background.jpg");
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    player.init(renderer);
    isRunning = true;
    return true;
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        player.handleEvent(event);
    }
}

void Game::update() {
    bgX -= 0;
    if (bgX <= -800) bgX = 0;

    player.update();
}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_Rect bgRect1 = { bgX, 0, 800, 600 };
    SDL_Rect bgRect2 = { bgX + 800, 0, 800, 600 };
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, &bgRect1);
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, &bgRect2);

    player.render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
