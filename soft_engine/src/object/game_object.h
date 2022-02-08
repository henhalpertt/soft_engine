#pragma once
#include "iobject.h"
#include "../physics/transoform.h"
#include "SDL.h"
#include <string>

struct Properties
{
	Properties(std::string textureID, float x, float y, int w, int h, SDL_RendererFlip flip = SDL_FLIP_NONE)
	{
		X = x;
		Y = y;
		m_Flip = flip;
		m_Width = w;
		m_Height = h;
		m_TextureID = textureID;
	}

	//variable members 
	std::string m_TextureID;
	int m_Width;
	int m_Height;
	float X;
	float Y;
	
	SDL_RendererFlip m_Flip;
};

class GameObject : public IObject
{

public:
	GameObject() :m_Transform{ nullptr }, m_Width{ 0 }, m_Height{ 0 }, m_TextureID{ "" }, m_Flip{SDL_FLIP_NONE}{}
	GameObject(Properties* props) :
							    m_Transform{new Transform(props->X, props->Y)},
								m_Width{ props->m_Width },
								m_Height{ props->m_Height },
								m_TextureID{ props->m_TextureID },
								m_Flip{ props->m_Flip } {}

	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;
	~GameObject() { delete m_Transform; }

protected:
	Transform* m_Transform;
	int m_Width;
	int m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};
