#ifndef POKEMONPP_ENTITIES_PLAYER_H
#define POKEMONPP_ENTITIES_PLAYER_H

#include "SDL.h"
#include "../Engine/GameEngine.h"
#include "../Engine/GameObject.h"
#include "../Manager/Texture/TextureManager.h"

class Player : public GameObject
{

private:
    std::string mTextureID;
    float mX;
    float mY;
    int mWidth;
    int mHeight;
    int mCurrentRow;
    int mCurrentFrame;
    float mTimerAnim;
public:
    Player(std::string textureID, int x, int y, int width, int height, int row);
    virtual void Draw(SDL_Renderer *pRenderer);
    void Update() override;
};

#endif //POKEMONPP_ENTITIES_PLAYER_H
