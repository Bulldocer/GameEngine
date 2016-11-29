#pragma once
#include "Singleton.h"
#include "RenderManager.h"

class ManagerOfManagers : public Singleton<ManagerOfManagers>
{
friend class Singleton<ManagerOfManagers>;

public:
	RenderManager& getRender();
	void initialice();
private:
	ManagerOfManagers();
	~ManagerOfManagers();
};

