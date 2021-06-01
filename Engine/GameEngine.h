#ifndef POKEMONPP_ENGINE_GAME_H
#define POKEMONPP_ENGINE_GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "Scene.h"
#include <string>

#define DEFAULT_TARGET_FRAME_RATE 30
#define MIN_FRAME_RATE 15

class GameEngine
{

private:
    SDL_Window   *mpWindow{};
    SDL_Renderer *mpRenderer{};
    char         *mpTitle{};
    bool          mbRunning{};
    int           mTargetFrameDuration{};
    float         mDeltaTime = 0;
    Scene        *mScene{};

public:
    GameEngine();
    ~GameEngine();

    int Init(char* title, int xpos, int ypos, int width, int height, int flags);
    void MainLoop();
    void LoadScene(Scene *scene);
    void HandleEvents();
    void Clean();

    void SetTargetFrameRate(int frameRate);
    float GetDeltaTime() const;
};

#endif
