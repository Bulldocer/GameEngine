#pragma once
#include "Component.h"
#include <iostream>
#include <vector>
class Object
{
public:
	Object();
	virtual ~Object();
	Component* getComponent(int pos);
	void addComponent(Component* component);
	void update();
	void close();
private:

	std::vector<Component*> components;	
};

