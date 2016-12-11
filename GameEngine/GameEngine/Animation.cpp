#include "Animation.h"
#include "ManagerOfManagers.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::render() {
	//Render current frame
	SDL_Rect* currentClip = &gSpriteClips[frame / ANIMATION_FRAMES];
	gSpriteSheetTexture.render((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 2, currentClip);

	//Update screen
	SDL_RenderPresent(ManagerOfManagers::GetInstance().getRender().gRenderer);

	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 4 >= ANIMATION_FRAMES)
	{
		frame = 0;
	}

}
