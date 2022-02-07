#include "engine.h"
#include "../graphics/texture_manager.h"
#include "../physics/vector2d.h"
#include "../physics/transoform.h"

bool Engine::Init()
{
	// check video / image initialization 
	if (!SDL_Init(SDL_INIT_VIDEO) && !IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
	{
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		m_IsRunning = false;
		return m_IsRunning;
	}

	// window
	m_Window = SDL_CreateWindow(
		"Soft-Engine",
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		SCREEN_WIDTH, 
		SCREEN_HEIGHT, 
		0);
	if (!m_Window)
	{
		SDL_Log("Failed to create a Window: %s", SDL_GetError());
		m_IsRunning = false;
		return false;
	}

	//renderer
	m_Renderer = SDL_CreateRenderer(
		m_Window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	if (!m_Renderer)
	{
		SDL_Log("Failed to create a Renderer: %s", SDL_GetError());
		m_IsRunning = false;
		return false;
	}
	
	TextureManager::GetInstance()->Load("tree", "assets/tree.png");
	Transform tf;
	tf.Log();

	m_IsRunning = true;
	return m_IsRunning;
}

bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
	return true;
}

void Engine::Update()
{
	//SDL_Log("UpdateLog");
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 210, 254, 255);
	SDL_RenderClear(m_Renderer);

	TextureManager::GetInstance()->Draw("tree", 100, 100, 591, 651, SDL_FLIP_NONE);
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			Quit();
			break;
	}
}


void Engine::Quit()
{
	m_IsRunning = false;
}