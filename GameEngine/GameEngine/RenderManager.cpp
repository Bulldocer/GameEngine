#include "RenderManager.h"
#include <iostream>
#include <cstring>
#include <string>


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
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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

				//Initialize Text library
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}else{
					gFont = TTF_OpenFont("Fonts/ArcadeClassic.ttf", 28);
				}
			}
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
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

void RenderManager::drawTexture(SDL_Surface* surface,SDL_Texture* texture, float x, float y, double angle, SDL_Point* center)
{
	SDL_Rect stretchRect;
	stretchRect.x = x;
	stretchRect.y = y;
	stretchRect.h = surface->h;
	stretchRect.w = surface->w;
	SDL_RenderCopyEx(gRenderer, texture, NULL, &stretchRect, angle, center, SDL_FLIP_NONE);
}

void RenderManager::drawText(const char* text) {
	SDL_Color textColor = { 255, 255, 255 };
	if (gFont != NULL) {
		SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text, textColor);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		SDL_Rect stretchRect;
		stretchRect.x = 20;
		stretchRect.y = 60;
		stretchRect.h = textSurface->h;
		stretchRect.w = textSurface->w;
		SDL_RenderCopy(gRenderer, texture, NULL, &stretchRect);
		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(texture);
	}
}

void RenderManager::close() {
	//Deallocate surface
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* RenderManager::loadTexture(SDL_Surface* surface)
{
	//The final texture
	SDL_Texture* newTexture = NULL;
	newTexture = SDL_CreateTextureFromSurface(gRenderer, surface);
	if (newTexture == NULL)
	{
		printf("Unable to create texture from surface! SDL Error: %s\n",SDL_GetError());
	}
	return newTexture;
}

void RenderManager::loadScore(int se) {
	score = se;
}

void RenderManager::update() {
	std::string aux = "SCORE " + std::to_string(score);
	this->drawText(aux.c_str());
	SDL_RenderPresent(gRenderer);
}

void RenderManager::clearScreen() {
	SDL_RenderClear(gRenderer);
}