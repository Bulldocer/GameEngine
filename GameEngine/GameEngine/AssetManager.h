#pragma once
#include "Singleton.h"
class AssetManager : public Singleton <AssetManager>
{
	friend class Singleton <AssetManager>;
private:
	AssetManager();
	~AssetManager();
};

