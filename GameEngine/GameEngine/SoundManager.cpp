#include "SoundManager.h"
#include <SDL.h>



SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::init() {
	
	//Initialize SDL
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	}
	else {
		//Initialize SDL_mixer
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		}
	}

}

void SoundManager::close() {
	//Quit SDL subsystems
	Mix_Quit();
}

void SoundManager::playMusic(Mix_Music* music) {
	
	Mix_PlayMusic(music, -1);
}

void SoundManager::playEffect(Mix_Chunk* effect) {
	Mix_PlayChannel(-1, effect, 0);
}

Mix_Music* SoundManager::loadMusic(char* path) {
	Mix_Music* a= Mix_LoadMUS(path);
	if (a == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
	return a;
}

Mix_Chunk* SoundManager::loadSoundEffect (char* path) {
	Mix_Chunk* a= Mix_LoadWAV(path);
	if (a == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	return a;
}