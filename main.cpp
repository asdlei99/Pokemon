#include <windows.h>
#include <iostream>
#include "Engine/GameEngine.h"

using namespace std;

GameEngine* g_game = nullptr;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    g_game = new GameEngine();
    g_game->Init("Pokemon Émeraude", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    g_game->MainLoop();
    return 0;
}
