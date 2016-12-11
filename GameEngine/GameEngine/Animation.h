#pragma once
#include <SDL.h>
#include "LTexture.h"
class Animation
{
public:
	Animation();
	~Animation();
	const int ANIMATION_FRAMES = 0;
	SDL_Rect gSpriteClips[ANIMATION_FRAMES];
	LTexture gSpriteSheetTexture;
	int frame = 0;
	void render();
};

