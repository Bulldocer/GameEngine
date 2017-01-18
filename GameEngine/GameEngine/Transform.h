#pragma once
#include "Component.h"
#include <SDL.h>
class Transform : public Component
{
public:
	Transform();
	~Transform();
	float x;
	float y;
	double angle;
	SDL_Point* center;
};

