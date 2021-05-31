#include <windows.h>
#include <iostream>
#include "Game/Game.h"

using namespace std;

Game* g_game = nullptr;
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    g_game = new Game();
    g_game->init("Pokemon Émeraude", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

<<<<<<< Updated upstream
    while (g_game->isRunnig())
=======
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);

    SDL_Window * window = SDL_CreateWindow("Pokemon Emeraude",
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = IMG_Load("test.jpg");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

    while (!quit)
>>>>>>> Stashed changes
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
        Sleep(10);
    }
    g_game->clean();

    return 0;
}
