#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

Component Object::getComponent(int pos) {
	return components[pos];
};

void Object::update() {

};
