#include "TextureManager.h"

TextureManager *TextureManager::spInstance = nullptr;

bool TextureManager::load(const std::string& filePath,const std::string& id, SDL_Renderer *pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(filePath.c_str());

    if (pTempSurface == nullptr)
        return false;

    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if (pTexture != nullptr)
    {
        mTextureMap.insert_or_assign(id, pTexture);
        return true;
    }

    return false;
}

void TextureManager::draw(const std::string& id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
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

void TextureManager::drawFrame(const std::string& id, int x, int y, int width, int height, int currentRow, int currentFrame,
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
    if (spInstance == nullptr)
        spInstance = new TextureManager();

    return spInstance;
}


