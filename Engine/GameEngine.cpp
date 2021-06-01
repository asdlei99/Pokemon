#include "GameEngine.h"

GameEngine::GameEngine()
= default;

GameEngine::~GameEngine()
{
    SDL_DestroyWindow(mpWindow);
    SDL_DestroyRenderer(mpRenderer);
    SDL_Quit();
}

int GameEngine::Init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        mpWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    else
        return -1;

    if (mpWindow != nullptr)
        mpRenderer = SDL_CreateRenderer(mpWindow, -1, 0);
    else
        return -1;

    if (mpRenderer == nullptr)
        return -1;

    this->mbRunning = true;
    return 0;
}

void GameEngine::MainLoop()
{
    while (this->IsRunnig())
    {
        auto frameStart = SDL_GetTicks();

        this->HandleEvents();

        if( mScene != nullptr )
            mScene->Update();

        auto frameDuration = SDL_GetTicks() - frameStart;
        if( frameDuration < TARGET_DURATION )
            SDL_Delay(TARGET_DURATION-frameDuration);
        SDL_SetWindowTitle(mpWindow,("Pokemon Émeraude | FPS:"+std::to_string(1000/(SDL_GetTicks() - frameStart))).c_str());
    }
    this->Clean();
}

void GameEngine::HandleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                mbRunning = false;
                break;
            default:
                break;
        }
    }
}

void GameEngine::Clean()
{
    SDL_DestroyWindow(mpWindow);
    SDL_DestroyRenderer(mpRenderer);
    SDL_Quit();
}

bool GameEngine::IsRunnig() const
{
    return this->mbRunning;
}

void GameEngine::LoadScene(Scene *scene)
{
    this->mScene = scene;
}

