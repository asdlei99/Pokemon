#ifndef POKEMONPP_ENGINE_GAMEOBJECT_H
#define POKEMONPP_ENGINE_GAMEOBJECT_H

class GameObject
{
public:
    virtual void Draw() = 0;
    virtual void Update() = 0;
};

#endif
