#include "TextureManager.h"

bool TextureManager::load(char *filePath, char *id, SDL_Renderer *pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(filePath);

    if (pTempSurface == nullptr)
        return false;

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if (pTexture != nullptr)
    {
        mTextureMap.at(id) = pTexture;
        return true;
    }

    return false;
}

void TextureManager::draw(char *id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = width;
    srcRect.h = height;

    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;

    SDL_RenderCopyEx(pRenderer, mTextureMap.at(id), &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::drawFrame(char *id, int x, int y, int width, int height, int currentRow, int currentFrame,
                               SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y =  height * (currentRow - 1);
    srcRect.w = width;
    srcRect.h = height;

    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;

    SDL_RenderCopyEx(pRenderer, mTextureMap.at(id), &srcRect, &destRect, 0, nullptr, flip);
}
TextureManager *TextureManager::Instance()
{
    if (s_pInstance == nullptr)
    {
        s_pInstance = new TextureManager();
        return s_pInstance;
    }

    return s_pInstance;
}


