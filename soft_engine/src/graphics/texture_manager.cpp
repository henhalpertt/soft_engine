#include "texture_manager.h"
#include "../core/engine.h"

bool TextureManager::Load(std::string id, std::string filename)
{
	//need a surface to load textures 
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (!surface)
	{
		SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
		return false;
	}
	Engine* engine = Engine::GetInstance();
	SDL_Texture* texture = SDL_CreateTextureFromSurface(engine->GetRenderer(), surface);
	if (!texture)
	{
		SDL_Log("Failed to create texture: %s", SDL_GetError());
		return false;
	}
	//adding texture to texture map 
	m_TextureMap[id] = texture;
	
	return true;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { 0, 0, width, height }; // topleftX, topleftY, bottomrightX , bottomRightY
	SDL_Rect destRect = { x, y, width, height };
	SDL_RenderCopyEx(
		Engine::GetInstance()->GetRenderer(),
		m_TextureMap[id],
		&srcRect,
		&destRect,
		0,
		nullptr,
		flip);

}

void TextureManager::DrawFrame(std::string id, int x, int y, int w, int h, int row, int frame, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { w*frame, h*(row-1), w, h};
	SDL_Rect destRect = { x, y, w, h };
	SDL_RenderCopyEx(
		Engine::GetInstance()->GetRenderer(),
		m_TextureMap[id],
		&srcRect,
		&destRect,
		0,
		nullptr,
		flip);
}

void TextureManager::Drop(std::string id)
{
	//destroy texture
	SDL_DestroyTexture(m_TextureMap[id]);
	//rmv from map
	m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
	// clean all textures 
	std::map<std::string, SDL_Texture*>::const_iterator  itr;
	for (itr = m_TextureMap.cbegin(); itr != m_TextureMap.cend(); ++itr)
		SDL_DestroyTexture(itr->second);
	m_TextureMap.clear();

	SDL_Log("Map cleaned");
}

