#ifndef POKEMONPP_ENGINE_GAME_H
#define POKEMONPP_ENGINE_GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "Scene.h"
#include <string>

#define TARGET_FPS 60
#define TARGET_DURATION (1000 / TARGET_FPS)

class GameEngine
{

private:
    bool mbRunning{};
    SDL_Window *mpWindow{};
    SDL_Renderer *mpRenderer{};
    Scene *mScene{};

public:
    GameEngine();
    ~GameEngine();

    int Init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void MainLoop();
    void LoadScene(Scene *scene);
    void HandleEvents();
    void Clean();
    [[nodiscard]] bool IsRunnig() const;
};

#endif
