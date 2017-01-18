#include "TimeManager.h"
#include <SDL.h>



TimeManager::TimeManager()
{
}


TimeManager::~TimeManager()
{
}

void TimeManager::init() {
	past = SDL_GetTicks();
}
bool TimeManager::newFrame() {
	int now = SDL_GetTicks();
	int timeElapsed = now - past;
	if (timeElapsed >= UPDATE_INTERVAL) {
		past = now;
		return true;
	}
	else {
		return false;
	}	
}
