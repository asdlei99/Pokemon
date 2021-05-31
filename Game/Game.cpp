#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

int Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    else
        return -1;

    if (m_pWindow != nullptr)
        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    else
        return -1;

    if (m_pRenderer != nullptr)
    {

    }

    this->m_bRunning = true;
    return 0;
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
        switch (event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
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
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool Game::isRunnig()
{
    return this->m_bRunning;
}