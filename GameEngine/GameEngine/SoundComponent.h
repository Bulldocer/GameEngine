#pragma once
#include "Component.h"
#include "SoundSource.h"
#include <SDL_mixer.h>
#include <stdio.h>
class SoundComponent : public Component
{
public:
	SoundComponent();
	~SoundComponent();
	void loadMusic(char* path);
	void loadEffect(char* path);
	void playMusic();
	void playEffect();
	void close();
private:
	Mix_Music* music;
	Mix_Chunk* effect;
};

