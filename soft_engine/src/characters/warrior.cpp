#include "warrior.h"
#include "../graphics/texture_manager.h"
#include "SDL.h"

Warrior::Warrior()
	: m_Row{ 1 }, m_Frame{ 0 }, m_FrameCount{ 12 }, m_AnimationSpeed{ 200 }
{
}

Warrior::Warrior(Properties* props)
	: Character(props), m_Row{ 1 }, m_Frame{ 0 }, m_FrameCount{ 12 }, m_AnimationSpeed{ 200 }
{
}

void Warrior::Draw()
{
	TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame, SDL_FLIP_NONE);
}

void Warrior::Update(float dt)
{
	m_Frame = (SDL_GetTicks() / m_AnimationSpeed) % m_FrameCount;
}

void Warrior::Clean()
{
	TextureManager::GetInstance()->Clean();
}