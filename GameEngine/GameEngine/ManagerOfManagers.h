#pragma once
#include "Singleton.h"
#include "RenderManager.h"
#include "SoundManager.h"

class ManagerOfManagers : public Singleton<ManagerOfManagers>
{
friend class Singleton<ManagerOfManagers>;

public:
	RenderManager& getRender();
	SoundManager& getSound();
	void initialice();
private:
	ManagerOfManagers();
	~ManagerOfManagers();
};

