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
			//Main loop flag
			bool quit = false;
			//Event handler
			SDL_Event e;
			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				//Apply the image
				ManagerOfManagers::GetInstance().getRender().drawSurface(image, 100, 100);
				//Update the surface
				SDL_UpdateWindowSurface(ManagerOfManagers::GetInstance().getRender().gWindow);				
			}
				
		}
	}
	//Deallocate surface
	SDL_FreeSurface(image);
	image = NULL;

	ManagerOfManagers::GetInstance().getRender().close();

	return 0;
}