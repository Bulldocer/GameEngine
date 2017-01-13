#include "ManagerOfManagers.h"


const float        UPDATE_INTERVAL = 1000.0f / 60.0f;
int main(int argc, char* args[])
{	
	ManagerOfManagers::CreateSingleton();

	ManagerOfManagers::GetInstance().initialice();

	Object* girl = new Object;
	girl->init();
	girl->transform->x = 100;
	girl->transform->y = 100;
	girl->image->loadSprite("Images/surprise.png");

	ManagerOfManagers::GetInstance().getObjects().newObject(girl);

	// Time manager
	int past = SDL_GetTicks();
	int now = past;
	int pastFps = past;

	//While application is running
	while (!ManagerOfManagers::GetInstance().getInput().quit)
	{
		int timeElapsed = 0;
		ManagerOfManagers::GetInstance().update();

		// Update logic
		now = SDL_GetTicks();
		timeElapsed = now - past;
		if (timeElapsed >= UPDATE_INTERVAL) {
			past = now;
			if (ManagerOfManagers::GetInstance().getInput().mKeys[SDLK_LEFT]) {
				girl->transform->x -= 10;
			}
			if (ManagerOfManagers::GetInstance().getInput().mKeys[SDLK_RIGHT]) {
				girl->transform->x += 10;
			}
			ManagerOfManagers::GetInstance().getRender().clearScreen();
		}
	}
	ManagerOfManagers::GetInstance().close();


	return 0;
}
