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
	SDL_Surface* loadSurfaceBMP(char* path);  //pasamos la direccion de la imagen y devuelve un puntero de una superficie con la imagen
	SDL_Surface* loadSurfacePNG(char* path);
	void close();
	void update();
	void drawSurface(SDL_Surface* surface, float x, float y); //dibuja la superficie optimizada a nuestra ventana en una posición determinada
	//SDL_Texture* loadTexture(SDL_Surface* surface);  //carga una hoja de sprites COSAS DEL RENDER QUE NO FUNCIONAN
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;
	//The window renderer COSAS PARA ANIMAR QUE NO FUNCIONAN
	//SDL_Renderer* gRenderer = NULL;
	
private:	
	RenderManager();
	~RenderManager();
};

