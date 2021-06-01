#include <windows.h>
#include <iostream>
#include "Engine/GameEngine.h"
#include "Entities/Player.h"

using namespace std;

GameEngine* g_game = nullptr;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    g_game = GameEngine::Instance();
    g_game->Init("Pokemon Émeraude", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    auto *player = new Player("test", 50, 50, 64, 64, 3);
    auto *scene = new Scene();
    scene->AddGameObject(player);
    g_game->LoadScene(scene);
    g_game->MainLoop();
    return 0;
}
