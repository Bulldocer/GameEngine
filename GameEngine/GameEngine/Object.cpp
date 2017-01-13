#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

void Object::update() {
	image->update();
};
void Object::close() {
	image->close();
	sound->close();
	delete transform;
	delete collider;
	delete sound;
	delete image;
};

void Object::init() {
	transform = new Transform;
	transform->x = 0;
	transform->y = 0;
	collider = new Collider;
	sound = new SoundComponent;
	image = new ImageComponent;
	image->setTransform(transform);
}

