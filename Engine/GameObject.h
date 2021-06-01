#ifndef POKEMONPP_ENGINE_GAMEOBJECT_H
#define POKEMONPP_ENGINE_GAMEOBJECT_H

#include "SDL.h"

class GameObject
{
public:
    virtual void Draw(SDL_Renderer *pRenderer) = 0;
    virtual void Update() = 0;
};

#endif
