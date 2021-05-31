#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
    SDL_DestroyWindow(mpWindow);
    SDL_DestroyRenderer(mpRenderer);
    SDL_Quit();
}

int Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        mpWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    else
        return -1;

    if (mpWindow != nullptr)
        mpRenderer = SDL_CreateRenderer(mpWindow, -1, 0);
    else
        return -1;

    if (mpRenderer != nullptr)
    {

    }

    this->mbRunning = true;
    return 0;
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
        switch (event.type)
        {
            case SDL_QUIT:
                mbRunning = false;
                break;
            default:
                break;
        }
}

void Game::update()
{

}

void Game::render()
{

}

void Game::clean()
{
    SDL_DestroyWindow(mpWindow);
    SDL_DestroyRenderer(mpRenderer);
    SDL_Quit();
}

bool Game::isRunnig()
{
    return this->mbRunning;
}