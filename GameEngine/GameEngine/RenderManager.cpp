#include "RenderManager.h"



RenderManager::RenderManager()
{
}


RenderManager::~RenderManager()
{
}

bool RenderManager:: openWindow() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}
SDL_Surface* RenderManager::loadSurface(char* path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}
void RenderManager::drawSurface(SDL_Surface* surface, float x, float y)
{
	//Apply the image stretched
	if (surface->h > gScreenSurface->h)
	{
		SDL_Rect stretchRect;
		stretchRect.x = x;
		stretchRect.y = y;
		stretchRect.w = (gScreenSurface->h * surface->w) / surface->h;
		stretchRect.h = gScreenSurface->h;
		SDL_BlitScaled(surface, NULL, gScreenSurface, &stretchRect);
	}
	else if (surface->w > gScreenSurface->w)
	{
		SDL_Rect stretchRect;
		stretchRect.x = x;
		stretchRect.y = y;
		stretchRect.w = gScreenSurface->w;
		stretchRect.h = (gScreenSurface->w * surface->h) / surface->w;
		SDL_BlitScaled(surface, NULL, gScreenSurface, &stretchRect);
	}
	else
		SDL_BlitSurface(surface, NULL, gScreenSurface, NULL);
}
void RenderManager::close() {
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}