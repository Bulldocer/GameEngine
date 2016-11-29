#pragma once
#include "Component.h"
class Object
{
public:
	Object();
	virtual ~Object();
	Component getComponent(int pos);
	void update();
private:
	Component components [];
};

