#include "Logic.h"
#include "ManagerOfManagers.h"
#include "Collider.h"
#include "ImageComponent.h"
#include "SoundComponent.h"
#include "Transform.h"


Logic::Logic()
{
}


Logic::~Logic()
{
}
void Logic::init() {
	Object* obj = new Object;
	trans = new Transform;
	Collider* col = new Collider;
	SoundComponent* sound = new SoundComponent;
	ImageComponent* img = new ImageComponent;

	trans->x = 100;
	trans->y = 100;

	sound->loadMusic("Sound/La_cabalgata_de_las_Valkirias_-_Richard_Wagner.wav");

	img->setTransform(trans);
	img->loadSprite("Images/surprise.png");

	obj->addComponent(trans);
	obj->addComponent(sound);
	obj->addComponent(img);
	ManagerOfManagers::GetInstance().getObjects().newObject(obj);
}
void Logic::update() {
	if (ManagerOfManagers::GetInstance().getInput().mKeys[SDLK_LEFT]) {
		trans->x +=10;
		
	}
}
