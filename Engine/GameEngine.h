#ifndef POKEMONPP_ENGINE_GAME_H
#define POKEMONPP_ENGINE_GAME_H

#include <string>
#include "Scene.h"

#define DEFAULT_TARGET_FRAME_RATE 60
#define MIN_FRAME_RATE 15

class GameEngine
{

private:
    SDL_Window   *mpWindow{};
    SDL_Renderer *mpRenderer{};
    char         *mpTitle{};
    bool          mbRunning{};
    int           mTargetFrameDuration{};
    float         mDeltaTime = 0.0f;
    Scene        *mScene{};

    static GameEngine *spInstance;
    GameEngine() = default;

public:
    ~GameEngine();

    static GameEngine *Instance();
    int Init(char* title, int xpos, int ypos, int width, int height, int flags);
    void MainLoop();
    void LoadScene(Scene *scene);
    void HandleEvents();
    void Clean();

    void SetTargetFrameRate(int frameRate);
    float GetDeltaTime() const;
    SDL_Renderer *getRenderer() const;
};

#endif
