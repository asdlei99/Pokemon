#include "Player.h"

Player::Player(std::string textureID, int x, int y, int width, int height, int row)
{
    this->mTextureID = textureID;
    this->mX = x;
    this->mY = y;
    this->mWidth = width;
    this->mHeight = height;
    this->mCurrentRow = row;
    this->mCurrentFrame = 1;
    this->mTimerAnim = 0.0f;
    TextureManager::Instance()->load(R"(C:\Users\Adam\Desktop\PokemonPP\ressource\assets\test.png)", "test", GameEngine::Instance()->getRenderer());
}

void Player::Draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->drawFrame(this->mTextureID, this->mX, this->mY, this->mWidth, this->mHeight,
                                          this->mCurrentRow, this->mCurrentFrame, pRenderer);
}

void Player::Update()
{
    this->mX += 60*GameEngine::Instance()->GetDeltaTime();
    this->mTimerAnim += 5*GameEngine::Instance()->GetDeltaTime();
    this->mCurrentFrame = (int)(this->mTimerAnim) % 4;
}
