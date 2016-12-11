#include "Singleton.h"
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string.h>
#include <array>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
class RenderManager : public Singleton<RenderManager>
{
friend class Singleton<RenderManager>;
public:
	bool openWindow(); //crea y devuelve un puntoro a la ventana
	SDL_Surface* loadSurface(char* path);  //pasamos la direccion de la imagen y devuelve un puntero de una superficie con la imagen
	void close();
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;
	void drawSurface(SDL_Surface* surface, float x, float y);//dibuja la superficie optimizada a nuestra ventana en una posición determinada
	//SDL_Surface* images[]; // Esto deberia ser un array donde metamos y quitemos las diferentes imagenes, para que se encarge el render de 
							// vaciar las diferentes superficies que utilizemos y no otro componente y que luego la funcion close()/deleteSurface()
							// se encargen de liberar el espacio
	//void deleteSurface(int pos);
private:	
	RenderManager();
	~RenderManager();
};

