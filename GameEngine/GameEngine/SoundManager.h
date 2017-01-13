#pragma once

#include "Singleton.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

class SoundManager : public Singleton<SoundManager>
{
	friend class Singleton<SoundManager>;
public:
	void init();
	void close();
	void playMusic(Mix_Music* music);
	void playEffect(Mix_Chunk* effect);
	Mix_Chunk* loadSoundEffect(char* path);
	Mix_Music* loadMusic(char* path);

private:
	SoundManager();
	~SoundManager();
};

