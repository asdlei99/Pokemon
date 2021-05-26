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
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
        pTempSurface = IMG_Load("../ressource/img/pokemon_anim.png");
        pTempSurface2 = IMG_Load("../ressource/img/test.png");
        pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        pTexture2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface2);
        m_sourceRectangle.x = 0;
        m_sourceRectangle.y = 128;
        m_destinationRectangle.x = 28;
        m_destinationRectangle.y = 0;
        m_sourceRectangle.h = m_destinationRectangle.h = 64;
        m_sourceRectangle.w = m_destinationRectangle.w = 64;

        m_sourceRectangle2.x = 0;
        m_sourceRectangle2.y = 0;
        m_sourceRectangle2.w = 64;
        m_sourceRectangle2.h = 64;
        m_destinationRectangle2.x = 0;
        m_destinationRectangle2.y = 17;
        m_destinationRectangle2.w = 55;
        m_destinationRectangle2.h = 55;


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
    m_sourceRectangle.x = 64 * int((SDL_GetTicks() / 200) % 4);
    m_destinationRectangle.x += 1;
    m_sourceRectangle2.x = 64 * int((SDL_GetTicks() / 200) % 4);
    m_destinationRectangle2.x += 1;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderCopy(m_pRenderer, pTexture2, &m_sourceRectangle2, &m_destinationRectangle2);
    SDL_RenderPresent(m_pRenderer);
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