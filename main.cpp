#include <windows.h>
#include <iostream>
#include "Game/Game.h"

using namespace std;

Game* g_game = nullptr;
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    g_game = new Game();
    g_game->init("Pokemon Émeraude", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);


    while (g_game->isRunnig())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
        Sleep(10);
    }
    g_game->clean();

    return 0;
}
