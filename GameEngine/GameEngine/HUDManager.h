#pragma once
#include "Singleton.h"
class HUDManager : public Singleton <HUDManager>
{
	friend class Singleton <HUDManager>;
private:
	HUDManager();
	~HUDManager();
};

