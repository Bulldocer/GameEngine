#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;
private:
	InputManager();
	~InputManager();
};

