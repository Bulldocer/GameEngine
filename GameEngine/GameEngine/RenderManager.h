#pragma once
#include "Singleton.h"
//Using SDL, SDL_image and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
class RenderManager : public Singleton<RenderManager>
{
friend class Singleton<RenderManager>;
public:
	bool openWindow(); //crea y devuelve un puntoro a la ventana	
	void close();
	void update();
	void clearScreen();
	void drawTexture(SDL_Surface* texture, float x, float y); //dibuja una textura en una posición determinada

	SDL_Surface* loadSurfacePNG(char* path);
	SDL_Texture* loadTexture(SDL_Surface* surface);  //cambia una superficie a una textura para dibujarla con el render
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;
	//The window renderer
	SDL_Renderer* gRenderer = NULL;
	
private:	
	RenderManager();
	~RenderManager();
};

