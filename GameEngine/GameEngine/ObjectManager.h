#pragma once
#include "Singleton.h"
#include "Object.h"
class ObjectManager : public Singleton<ObjectManager>
{
	friend class Singleton<ObjectManager>;
public:
	void newObject(Object* object);
	void deleteObject(Object* object);
	void updateObjects();
	void closeObjects();
private:
	ObjectManager();
	~ObjectManager();
	std::vector<Object*> objects;
};

