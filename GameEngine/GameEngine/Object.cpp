#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

Component* Object::getComponent(int pos) {
	return components.at(pos);
};
void Object::addComponent(Component* component) {
	components.push_back(component);
};


void Object::update() {
	for (unsigned i = 0; i<components.size(); i++)
		components.at(i)->update();
};
void Object::close() {
	for (unsigned i = 0; i < components.size(); i++)
	{
		components.at(i)->close();
		delete components.at(i);
	}		
};

