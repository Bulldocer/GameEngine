#include "ManagerOfManagers.h"



ManagerOfManagers::ManagerOfManagers()
{
}


ManagerOfManagers::~ManagerOfManagers()
{
}

void ManagerOfManagers::initialice() {
		
	InputManager::CreateSingleton();
	SoundManager::CreateSingleton();
	ObjectManager::CreateSingleton();
	RenderManager::CreateSingleton();

	this->getInput().init();
	SoundManager::GetInstance().init();
	if (!ManagerOfManagers::GetInstance().getRender().openWindow())
	{
		printf("Failed to initialize!\n");
		this->getInput().quit = true;
	}
	else
	{
		this->getInput().quit = false;
		logic.init();
	}
}

RenderManager& ManagerOfManagers:: getRender() {
	return RenderManager::GetInstance();
};

SoundManager& ManagerOfManagers::getSound() {
	return SoundManager::GetInstance();
};

InputManager& ManagerOfManagers::getInput() {
	return InputManager::GetInstance();
}

ObjectManager& ManagerOfManagers::getObjects() {
	return ObjectManager::GetInstance();
}

void ManagerOfManagers::update() {
	//While application is running
	while (!this->getInput().quit)
	{
		//Handle events on queue
		this->getInput().update();
		logic.update();
		//Update objects and render them
		this->getObjects().updateObjects();
		//Update the surface
		this->getRender().update();
	}
	this->close();
}

void ManagerOfManagers::close() {
	this->getObjects().closeObjects();
	this->getSound().close();
	this->getRender().close();
}