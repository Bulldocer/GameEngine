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
	//Free the sound effects
	Mix_FreeChunk(gEffect1);
	Mix_FreeChunk(gEffect2);
	Mix_FreeChunk(gEffect3);
	Mix_FreeChunk(gEffect4);
	gEffect1 = NULL;
	gEffect2 = NULL;
	gEffect3 = NULL;
	gEffect4 = NULL;

	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	//Quit SDL subsystems
	Mix_Quit();
}

void SoundManager::playMusic() {
	//If there is no music playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(gMusic, -1);
	}
	else
	{
		//If the music is paused
		if (Mix_PausedMusic() == 1)
		{
			//Resume the music
			Mix_ResumeMusic();
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
		}
	}
}

/*void SoundManager::playEffect(std::string effect) {
	switch (effect) {
	case "effect1":
		Mix_PlayChannel(-1, gEffect1, 0);
		break;
	case "effect2":
		Mix_PlayChannel(-1, gEffect2, 0);
		break;
	case "effect3":
		Mix_PlayChannel(-1, gEffect3, 0);
		break;
	case "effect4":
		Mix_PlayChannel(-1, gEffect4, 0);
		break;
	default:
		break;
	}
}*/

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
