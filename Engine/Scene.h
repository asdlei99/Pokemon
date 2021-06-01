#ifndef POKEMONPP_ENGINE_SCENE_H
#define POKEMONPP_ENGINE_SCENE_H

#include <list>
#include "GameObject.h"

class Scene
{
private:
    std::list<GameObject*> mGameObjects{};
public:
    Scene();
    ~Scene();
    void AddGameObject(GameObject *gameObject);
    void Update();
    void Render(SDL_Renderer *pRenderer);
};

#endif