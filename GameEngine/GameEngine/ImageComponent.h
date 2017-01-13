#pragma once
#include "Component.h"
#include "Transform.h"
#include <SDL.h>
#include <SDL_image.h>

class ImageComponent : public Component
{
public:
	ImageComponent();
	~ImageComponent();
	void loadSprite(char* path);
	void setTransform(Transform* transform);
	void close();
	void update();
private:
	SDL_Surface* sprite;
	Transform* transform;
};

