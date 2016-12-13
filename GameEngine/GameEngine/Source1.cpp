#include "ManagerOfManagers.h"
#include <SDL.h>
#include "Animation.h"
int main(int argc, char* args[])
{	
	ManagerOfManagers::CreateSingleton();

	ManagerOfManagers::GetInstance().initialice();

	SDL_Surface* image = NULL;
	if (!ManagerOfManagers::GetInstance().getRender().openWindow())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		image = ManagerOfManagers::GetInstance().getRender().loadSurfacePNG("Images/loaded.png");
		if (image != NULL)
		{
			//Apply the image
			ManagerOfManagers::GetInstance().getRender().drawSurface(image,0,0);
			//Update the surface
			SDL_UpdateWindowSurface(ManagerOfManagers::GetInstance().getRender().gWindow);
			//Wait two seconds
			SDL_Delay(20000);
		}
	}
	//Deallocate surface
	SDL_FreeSurface(image);
	image = NULL;

	ManagerOfManagers::GetInstance().getRender().close();

	return 0;
}