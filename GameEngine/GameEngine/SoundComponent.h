#pragma once
#include "Component.h"
#include "SoundSource.h"
class SoundComponent : public Component
{
public:
	SoundComponent();
	~SoundComponent();
	SoundSource sound;
};

