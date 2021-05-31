#ifndef POKEMONPP_GAME_GAME_H
#define POKEMONPP_GAME_GAME_H

#include "SDL.h"
#include "SDL_image.h"

class Game
{

private:
    bool m_bRunning;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

public:
    Game();
    ~Game();

    int init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();

    bool isRunnig();
};

#endif
