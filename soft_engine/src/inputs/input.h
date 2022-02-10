#pragma once
#include "SDL.h"

// one instance of Input class
class Input
{
public:
	static Input* GetInstance()
	{
		static Input* s_Instance;
		if (!s_Instance)
			s_Instance = new Input();
		return s_Instance;
	}

	void Listen();
	bool GetKeyDown(SDL_Scancode a_key);
	void KeyUp();
	void KeyDown();

private:
	Input() : m_KeyStates{ SDL_GetKeyboardState(nullptr) } {}
	const Uint8* m_KeyStates; 
	
};