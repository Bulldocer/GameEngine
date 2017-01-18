#pragma once
#include "Singleton.h"
#include "RenderManager.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"

class ManagerOfManagers : public Singleton<ManagerOfManagers>
{
friend class Singleton<ManagerOfManagers>;

public:
	RenderManager& getRender();
	SoundManager& getSound();
	ObjectManager& getObjects();
	InputManager& getInput();
	TimeManager& getTime();
	void initialice();
	void update();
	void close();
private:
	ManagerOfManagers();
	~ManagerOfManagers();	
};

