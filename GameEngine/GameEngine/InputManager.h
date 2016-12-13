#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;
private:
//	SDL_Event event;
	InputManager();
	~InputManager();
};

