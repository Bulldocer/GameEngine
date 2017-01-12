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

		ManagerOfManagers::GetInstance().getSound().loadMusic("Sound/La_cabalgata_de_las_Valkirias_-_Richard_Wagner.wav");
		if (image != NULL)
		{
			//Main loop flag
			bool quit = false;
			//Event handler
			SDL_Event e;
			int x = 100;
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
					if (e.type == SDL_KEYDOWN)
					{
						if (e.key.keysym.sym == SDLK_1)
						{
							ManagerOfManagers::GetInstance().getSound().playMusic();
							x += 100;
						}
					}

				}
				//Apply the image
				ManagerOfManagers::GetInstance().getRender().drawSurface(image, x, 100);
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