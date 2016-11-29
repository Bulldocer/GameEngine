#include "ManagerOfManagers.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "ObjectManager.h"
#include "SoundManager.h"
#include "HUDManager.h"



ManagerOfManagers::ManagerOfManagers()
{
}


ManagerOfManagers::~ManagerOfManagers()
{
}

void ManagerOfManagers::initialice() {
		
	InputManager::CreateSingleton();
	AssetManager::CreateSingleton();
	SoundManager::CreateSingleton();
	ObjectManager::CreateSingleton();
	HUDManager::CreateSingleton();
	RenderManager::CreateSingleton();

}

RenderManager& ManagerOfManagers:: getRender() {
	return RenderManager::GetInstance();
};
