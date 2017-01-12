#pragma once

#include "Singleton.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

class SoundManager : public Singleton<SoundManager>
{
	friend class Singleton<SoundManager>;
public:
	//The music that will be played
	Mix_Music *gMusic = NULL;

	//The sound effects that will be used
	Mix_Chunk *gEffect1 = NULL;
	Mix_Chunk *gEffect2 = NULL;
	Mix_Chunk *gEffect3 = NULL;
	Mix_Chunk *gEffect4 = NULL;

	void init();
	void close();
	void playMusic();
	void playEffect(std::string effect);
	Mix_Chunk* loadSoundEffect(char* path);
	Mix_Music* loadMusic(char* path);

private:
	SoundManager();
	~SoundManager();
};

