#include "input.h"
#include "../core/engine.h"

void Input::Listen()
{
	SDL_Event event;
	Input* in = Input::GetInstance();
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				Engine::GetInstance()->Quit();
				break;

			case SDL_KEYDOWN:
				in->KeyDown();
				break;

			case SDL_KEYUP:
				in->KeyUp();
				break;
		}
	}
}

bool Input::GetKeyDown(SDL_Scancode a_key)
{
	// check if key was pushed
	return m_KeyStates[a_key] == 1;
}

void Input::KeyUp()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::KeyDown()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}