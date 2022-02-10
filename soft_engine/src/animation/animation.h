#pragma once
#include "SDL.h"
#include <string>

class Animation
{

public:
	Animation() { }

	void Update();
	void Draw(int x, int y, int spriteWidth, int spriteHeight);
	void SetProps(std::string textureID, int spriteRow, int frameCnt, int animSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
		int m_SpriteRow;
		int m_SpriteFrame;
		int m_AnimaSpeed;
		int m_FrameCount;
		std::string m_TextureID;
		SDL_RendererFlip m_Flip;
};
