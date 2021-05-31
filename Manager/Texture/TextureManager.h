#ifndef POKEMONPP_MANAGER_TEXTURE_TEXTUREMANAGER_H
#define POKEMONPP_MANAGER_TEXTURE_TEXTUREMANAGER_H

#include <map>
#include "SDL.h"
#include "SDL_image.h"

class TextureManager
{
private:
    static TextureManager *s_pInstance;
    std::map<char*, SDL_Texture*> mTextureMap;
    TextureManager()= default;
    ~TextureManager()=default;

public:
    static TextureManager *Instance();
    bool load (char *filePath, char *id, SDL_Renderer *pRenderer);
    void draw (char *id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame (char *id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif //POKEMONPP_MANAGER_TEXTURE_TEXTUREMANAGER_H
