#pragma once
#include "Component.h"
#include "Sprite.h"
class ImageComponent : public Component
{
public:
	ImageComponent();
	~ImageComponent();
	Sprite sprite;
	Sprite anim[];
};

