#include "Animation.h"
#include "ManagerOfManagers.h"

const int Animation::ANIMATION_FRAMES = 4;

Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::render(int x, int y) {
	//Render current frame
	SDL_Rect* currentClip = &gSpriteClips[frame / ANIMATION_FRAMES];
	gSpriteSheetTexture.render(x, y, currentClip);

	//Update screen
	

	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 4 >= ANIMATION_FRAMES)
	{
		frame = 0;
	}

}
