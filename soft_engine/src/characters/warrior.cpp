#include "warrior.h"
#include "../graphics/texture_manager.h"
#include "SDL.h"
#include "../inputs/input.h"

Warrior::Warrior(Properties* props)
	: Character(props)
{
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->SetProps(props->m_TextureID, 1, 8, 60, SDL_FLIP_NONE);
}

void Warrior::Draw()
{
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Update(float dt)
{	
	m_RigidBody->ResetForce();
	m_Width = 64;

	if(m_Flip == SDL_FLIP_HORIZONTAL)
		m_Animation->SetProps("player", 1, 15, 40, SDL_FLIP_HORIZONTAL);
	else
		m_Animation->SetProps("player", 1, 15, 40, SDL_FLIP_NONE);
	
	//move forward
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
	{
		m_RigidBody->ApplyForceX(5 * FORWARD);
		m_Width = 96;
		m_Flip = SDL_FLIP_NONE;
		m_Animation->SetProps("player_run", 1, 8, 60, SDL_FLIP_NONE);
	}

	//move backwards
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
	{
		m_RigidBody->ApplyForceX(5 * BACKWARDS);
		m_Width = 96;
		m_Flip = SDL_FLIP_HORIZONTAL;
		m_Animation->SetProps("player_run", 1, 8, 60, SDL_FLIP_HORIZONTAL);
	}

	m_Transform->TranslateX(m_RigidBody->Position().X);
	m_RigidBody->Update(0.5);
	m_Animation->Update();
}

void Warrior::Clean()
{
	TextureManager::GetInstance()->Clean();
}