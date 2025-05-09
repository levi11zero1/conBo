#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include "tank.h"
#include "EnemyTank.h"
#include "texture_manager.h"
#include "Explosion.h"
#include "explosion.h"
#include <fstream>


enum GameState {
    MENU,
    PLAYING,
    GAME_OVER,
    WIN
};

enum LEVEL
{
    EASY,
    MEDIUM,
    HARD,
    SUPER_HARD
};

class Game {
public:
    Game();
    void setGameSate(GameState status)
    {
        gameState = status;
    }
    GameState getGamesatus()
    {
        return gameState;
    }
private:
    GameState gameState;
};


class GameLevel
{
public:
    GameLevel()
    {
        gamelevel = MEDIUM;
    }
    LEVEL getGameLevel()
    {
        return gamelevel;
    }
    void setGameLevel(LEVEL level)
    {
        gamelevel = level;
    }
private:
    LEVEL gamelevel;
};



void handleEvents(SDL_Event& e, bool& running, Tank& tank, SDL_Renderer* renderer,std::vector<EnemyTank> enemies);
void update(Tank& tank, std::vector<EnemyTank>& enemies, std::vector<Explosion>& explosions, SDL_Texture* explosionTexture1, SDL_Texture* explosionTexture2, SDL_Texture* explosionTexture3, Game& game, std::vector<std::pair<int, int>> indexOfZero, SDL_Renderer* renderer, int& score, const int& gamelevel);
void render(SDL_Renderer* renderer, Tank& tank, std::vector<EnemyTank>& enemies, std::vector<Explosion>& explosions, Game& game, bool& run, const int& score,int highscore);
void resetGame(Tank& tank, std::vector<EnemyTank>& enemies, std::vector<Explosion>& explosions, int& score,SDL_Renderer* renderer);
void getHighScore(int& hightScore);
void setHighScore(int& score,int& hightScore);
#endif
