#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {
    game = new Game();

    if (!game->init("Contra SDL2", 800, 600)) {
        return -1;
    }

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
        SDL_Delay(6);
    }

    game->clean();
    delete game;
    return 0;
}
