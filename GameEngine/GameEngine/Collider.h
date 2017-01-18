#pragma once
#include "Component.h"
#include <SDL.h>
class Collider : Component
{
public:
	Collider();
	~Collider();
	SDL_Rect stretchRect;
};

