#pragma once
#include "Component.h"
class Transform : public Component
{
public:
	Transform();
	~Transform();
	float x;
	float y;
	float direction[2];
};

