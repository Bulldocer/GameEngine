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
	sprite = NULL;
}

void ImageComponent::loadSprite(char* path) {
	sprite = ManagerOfManagers::GetInstance().getRender().loadSurfacePNG(path);
}

void ImageComponent::setTransform(Transform* trans) {
	transform = trans;
}

void ImageComponent::update() {
	if(sprite!=NULL)
		ManagerOfManagers::GetInstance().getRender().drawTexture(sprite,transform->x,transform->y);
}
