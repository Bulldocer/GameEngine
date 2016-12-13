#include "LTexture.h"
#include "ManagerOfManagers.h"



LTexture::LTexture()
{
}


LTexture::~LTexture()
{
}

bool LTexture::loadFromFile(char* path) {
	SDL_Surface* image = NULL;
	bool success = true;
	image = ManagerOfManagers::GetInstance().getRender().loadSurfacePNG(path);
	
	if (image == NULL)
		success = false;
	else
	{
		mWidth = image->w;
		mHeight = image->h;
		//mTexture = ManagerOfManagers::GetInstance().getRender().loadTexture(image);
	}
	SDL_FreeSurface(image);
	return success;
}

void LTexture::free() {
	//Free loaded texture
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
}

void LTexture::render(int x, int y, SDL_Rect* clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	//SDL_RenderCopy(ManagerOfManagers::GetInstance().getRender().gRenderer, mTexture, clip, &renderQuad);
}

int LTexture::getWidth(){
	return mWidth;
}
int LTexture::getHeight() {
	return mHeight;
}