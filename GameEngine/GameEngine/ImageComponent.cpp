#include "ImageComponent.h"
#include "ManagerOfManagers.h"



ImageComponent::ImageComponent()
{
}


ImageComponent::~ImageComponent()
{
}

void ImageComponent::close() {
	//Deallocate surface
	SDL_FreeSurface(sprite);
	SDL_DestroyTexture(texture);
	sprite = NULL;
	texture = NULL;
}

void ImageComponent::loadSprite(char* path) {
	sprite = ManagerOfManagers::GetInstance().getRender().loadSurfacePNG(path);
	texture = ManagerOfManagers::GetInstance().getRender().loadTexture(sprite);
	if (sprite != NULL)
		transform->center = new SDL_Point{ sprite->h / 2, sprite->w / 2 };
}

void ImageComponent::setTransform(Transform* trans) {
	transform = trans;
}

void ImageComponent::update() {
	if(sprite!=NULL)
		ManagerOfManagers::GetInstance().getRender().drawTexture(sprite,texture,transform->x,transform->y,transform->angle,transform->center);
}
