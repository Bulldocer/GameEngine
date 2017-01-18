#pragma once
#include "ImageComponent.h"
#include "SoundComponent.h"
#include "Transform.h"
class Object
{
public:
	Object();
	virtual ~Object();
	void init();
	void update();
	void close();
	Transform* transform;
	SoundComponent* sound;
	ImageComponent* image;
};

