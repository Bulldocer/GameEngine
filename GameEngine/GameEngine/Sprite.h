#pragma once
#include "Asset.h"
#include <string>
class Sprite : public Asset
{
public:
	Sprite();
	~Sprite();
	std::string source;
};

