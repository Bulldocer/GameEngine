#include "Singleton.h"
#include <stdio.h>
#include <cstdio>  
#include <map>
#include <SDL.h>

class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;
public:
	std::map<int, int>  mKeys;
	void EventManagement();
private:	
	void OnKeyDown(SDL_Event* event);
	void OnKeyUp(SDL_Event* event);
	InputManager();
	~InputManager();
};

