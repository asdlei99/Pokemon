#include "Scene.h"

Scene::Scene()
= default;

Scene::~Scene()
= default;

void Scene::AddGameObject(GameObject *gameObject)
{
    this->mGameObjects.push_back(gameObject);
}

void Scene::Update()
{
    for(GameObject *gameObject : mGameObjects){
        gameObject->Draw();
        gameObject->Update();
    }
}
