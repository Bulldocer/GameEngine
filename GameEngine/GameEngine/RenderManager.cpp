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
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			//Create renderer for window COSAS PARA ANIMAR QUE NO FUNCIONAN
			/*gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}*/
		}
	}

	return success;
}
SDL_Surface* RenderManager::loadSurfaceBMP(char* path)
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
SDL_Surface* RenderManager::loadSurfacePNG(char* path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, IMG_GetError());
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
/*void RenderManager::drawSurface(SDL_Surface* surface, float x, float y)
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
}*/
void RenderManager::drawSurface(SDL_Surface* surface, float x, float y)
{
	SDL_Rect stretchRect;
	stretchRect.x = x;
	stretchRect.y = y;
	stretchRect.h = surface->h;
	stretchRect.w = surface->w;
	SDL_BlitScaled(surface, NULL, gScreenSurface, &stretchRect);
}
void RenderManager::close() {
	//Deallocate surface
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	//Destroy window
	//SDL_DestroyRenderer(gRenderer); COSAS DE ANIMACION QUE NO FUNCIONAN
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	//gRenderer = NULL; COSAS DE ANIMACION QUE NO FUNCIONAN


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

/*SDL_Texture* RenderManager::loadTexture(SDL_Surface* surface)
{
	//The final texture
	SDL_Texture* newTexture = NULL;
	newTexture = SDL_CreateTextureFromSurface(gRenderer, surface);
	if (newTexture == NULL)
	{
		printf("Unable to create texture from surface! SDL Error: %s\n",SDL_GetError());
	}
	return newTexture;
}*/


void RenderManager::update() {
	SDL_UpdateWindowSurface(gWindow);
}