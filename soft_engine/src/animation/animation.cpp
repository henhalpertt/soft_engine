#include "animation.h"
#include "../graphics/texture_manager.h"

//Animation::Animation() { }

void Animation::Update()
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimaSpeed) % m_FrameCount;
}

void Animation::Draw(int x, int y, int spriteWidth, int spriteHeight)
{
	TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::SetProps(std::string textureID, int spriteRow, int frameCnt, int animSpeed, SDL_RendererFlip flip)
{
	m_TextureID = textureID;
	m_SpriteRow = spriteRow;
	m_FrameCount = frameCnt;
	m_AnimaSpeed = animSpeed;
	m_Flip = flip;
}