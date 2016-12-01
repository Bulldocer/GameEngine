#include "Singleton.h"
//Using SDL and standard IO
#include <SDL.h>
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
	bool loadMedia(char* direction);  //pasamos la direccion de la imagen y un puntero de una superficie para que la carge en dicha superficie
	SDL_Surface* loadSurface(char* path);
	void close();
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	SDL_Surface* gImage;
private:	
	RenderManager();
	~RenderManager();
};

