#pragma once
#include <SDL.h>
#include "LTexture.h"
class Animation
{
public:
	Animation();
	~Animation();
	static const int ANIMATION_FRAMES;
	SDL_Rect gSpriteClips[4];
	LTexture gSpriteSheetTexture;
	int frame = 0;
	void render(int x, int y);
};

