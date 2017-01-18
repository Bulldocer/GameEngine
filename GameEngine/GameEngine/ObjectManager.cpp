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

bool ObjectManager::checkCollision(Object* obj1, Object* obj2) {
	if (obj1->image->sprite != NULL && obj2->image->sprite != NULL) {
		SDL_Rect a;
		a.x = obj1->transform->x;
		a.y = obj1->transform->y;
		a.h = obj1->image->sprite->h;
		a.w = obj1->image->sprite->w;
		SDL_Rect b;
		b.x = obj2->transform->x;
		b.y = obj2->transform->y;
		b.h = obj2->image->sprite->h;
		b.w = obj2->image->sprite->w;

		//The sides of the rectangles
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		//Calculate the sides of rect A
		leftA = a.x;
		rightA = a.x + a.w;
		topA = a.y;
		bottomA = a.y + a.h;

		//Calculate the sides of rect B
		leftB = b.x;
		rightB = b.x + b.w;
		topB = b.y;
		bottomB = b.y + b.h;

		//If any of the sides from A are outside of B
		if (bottomA <= topB)
		{
			return false;
		}

		if (topA >= bottomB)
		{
			return false;
		}

		if (rightA <= leftB)
		{
			return false;
		}

		if (leftA >= rightB)
		{
			return false;
		}

		//If none of the sides from A are outside B
		return true;
	}
	return false;
}