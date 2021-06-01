#ifndef POKEMONPP_ENGINE_SCENE_H
#define POKEMONPP_ENGINE_SCENE_H

#include "GameObject.h"
#include <list>

class Scene
{
private:
    std::list<GameObject*> mGameObjects{};
public:
    Scene();
    ~Scene();
    void AddGameObject(GameObject *gameObject);
    void Update();
};

#endif