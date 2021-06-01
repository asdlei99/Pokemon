#include "GameEngine.h"

GameEngine::GameEngine()
{
    this->SetTargetFrameRate(DEFAULT_TARGET_FRAME_RATE);
}

GameEngine::~GameEngine()
{
    SDL_DestroyWindow(mpWindow);
    SDL_DestroyRenderer(mpRenderer);
    SDL_Quit();
}

int GameEngine::Init(char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        mpTitle = title;
        mpWindow = SDL_CreateWindow(mpTitle, xpos, ypos, width, height, flags);
    }
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
    while (mbRunning)
    {
        auto frameStart = SDL_GetTicks();

        this->HandleEvents();

        if( mScene != nullptr )
            mScene->Update();

        auto frameDuration = SDL_GetTicks() - frameStart;
        if( frameDuration < mTargetFrameDuration )
            SDL_Delay(mTargetFrameDuration-frameDuration);

        mDeltaTime = (float)(SDL_GetTicks() - frameStart)/1000.0f;

        char titleBuffer [50];
        sprintf(titleBuffer, "%s [ FPS : %d ]", mpTitle, (int)(1 / mDeltaTime));

        SDL_SetWindowTitle(mpWindow,titleBuffer);
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

void GameEngine::LoadScene(Scene *scene)
{
    this->mScene = scene;
}

void GameEngine::SetTargetFrameRate(int frameRate)
{
    if (frameRate<=MIN_FRAME_RATE)
        frameRate = MIN_FRAME_RATE;

    mTargetFrameDuration = 1000/frameRate;
}

float GameEngine::GetDeltaTime() const
{
    return mDeltaTime;
}

