#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <string>

// only one Textuer manager - using singleton DP
class TextureManager
{
public:
	static TextureManager* GetInstance()
	{
		static TextureManager* s_Instance;
		if (!s_Instance)
			s_Instance = new TextureManager();
		return s_Instance;
	}
	
	bool Load(std::string id, std::string filename);
	void Drop(std::string id);
	void Clean();

	void Draw(std::string id, int x, int y ,int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int w, int h, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager() {}
	std::map<std::string, SDL_Texture*> m_TextureMap; // [key:id, value:ptr to texture]

};
