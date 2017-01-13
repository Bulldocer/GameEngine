#include "SoundComponent.h"
#include "ManagerOfManagers.h"



SoundComponent::SoundComponent()
{
}


SoundComponent::~SoundComponent()
{
}

void SoundComponent::loadEffect(char* path) {
	effect = ManagerOfManagers::GetInstance().getSound().loadSoundEffect(path);
}

void SoundComponent::loadMusic(char* path) {
	music = ManagerOfManagers::GetInstance().getSound().loadMusic(path);
}

void SoundComponent::playMusic() {
	ManagerOfManagers::GetInstance().getSound().playMusic(music);
}
void SoundComponent::playEffect() {
	ManagerOfManagers::GetInstance().getSound().playEffect(effect);
}
void SoundComponent::close() {
	Component::close();
	//Free the sound effects
	Mix_FreeChunk(effect);
	effect= NULL;

	//Free the music
	Mix_FreeMusic(music);
	music = NULL;
}
