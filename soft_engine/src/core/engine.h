#pragma once
#include "SDL.h"
#include "SDL_image.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

// Engine class is a singleton class
class Engine
{
public:
	static Engine* GetInstance()
	{
		static Engine* s_Instance;
		if (!s_Instance)
			s_Instance = new Engine();
		return s_Instance;
	}

	bool Init();
	bool Clean();
	void Quit();

	void Update();
	void Render();
	void Events();

	inline bool IsRunning() { return m_IsRunning; }
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }


private:
	Engine() : m_IsRunning{ false }, m_Window{ nullptr }, m_Renderer{nullptr} {};
	bool m_IsRunning;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};

// ENGINE_H
