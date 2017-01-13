#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::updateObjects() {
	for (unsigned i = 0; i<objects.size(); i++)
		objects.at(i)->update();
}

void ObjectManager::closeObjects() {
	for (unsigned i = 0; i<objects.size(); i++)
		objects.at(i)->close();
}

void ObjectManager::newObject(Object* object) {
	objects.push_back(object);
}

void ObjectManager::deleteObject(Object* object) {
	for (unsigned i = 0; i < objects.size(); i++) {
		if (objects.at(i) == object) {
			objects.at(i)->close();
			delete object;
			objects.erase(objects.begin() + i);
			break;
		}
	}
}