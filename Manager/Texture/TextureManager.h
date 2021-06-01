#ifndef POKEMONPP_MANAGER_TEXTURE_TEXTUREMANAGER_H
#define POKEMONPP_MANAGER_TEXTURE_TEXTUREMANAGER_H

#include <map>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

class TextureManager
{
private:
    static TextureManager *spInstance;
    std::map<std::string, SDL_Texture*> mTextureMap;
    TextureManager()= default;
public:
    static TextureManager *Instance();
    bool load (const std::string& filePath, const std::string& id, SDL_Renderer *pRenderer);
    void draw (const std::string& id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame (const std::string& id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif //POKEMONPP_MANAGER_TEXTURE_TEXTUREMANAGER_H
