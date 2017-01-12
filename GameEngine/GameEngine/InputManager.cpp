#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::EventManagement()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			break;
		case SDL_KEYDOWN:
			OnKeyDown(&event);
			break;
		case SDL_KEYUP:
			OnKeyUp(&event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		case SDL_MOUSEMOTION:
			break;
		}
	}
}
void InputManager::OnKeyDown(SDL_Event* evt)
{
	mKeys[evt->key.keysym.sym] = 1;
}
void InputManager::OnKeyUp(SDL_Event* evt)
{
	mKeys[evt->key.keysym.sym] = 0;
}
