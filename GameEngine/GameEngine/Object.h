#pragma once
#include "Collider.h"
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
	Collider* collider;
	SoundComponent* sound;
	ImageComponent* image;
};

