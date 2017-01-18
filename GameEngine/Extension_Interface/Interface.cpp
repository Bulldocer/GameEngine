#include "Interface.h"
#include "ManagerOfManagers.h"



Interface::Interface()
{
}


Interface::~Interface()
{
}

void Interface::init(char* image, char* font, int numLives) {
	gFont = TTF_OpenFont(font, 28);
	ManagerOfManagers::GetInstance().getRender().loadFont(gFont);
	pathImage = image;
	for (int i = 0; i < numLives; i++) {
		Object* aux = new Object;
		aux->init();
		aux->transform->x = 20+ i*20;
		aux->transform->y = 20;
		aux->image->loadSprite(pathImage);
		lives.push_back(aux);
		ManagerOfManagers::GetInstance().getObjects().newObject(aux);
	}
}

void Interface::addLives() {
	Object* aux = new Object;
	aux->init();
	aux->transform->x = 20;
	aux->transform->y = 20;
	aux->image->loadSprite(pathImage);
	lives.push_back(aux);
	ManagerOfManagers::GetInstance().getObjects().newObject(aux);
}

void Interface::subLives() {
	if (lives.size() > 0) {
		Object* aux = lives.back();
		lives.pop_back();
		ManagerOfManagers::GetInstance().getObjects().deleteObject(aux);
	}
	else {
		ManagerOfManagers::GetInstance().getInput().quit = true;
	}
}

void Interface::addScore(int add) {
	score += add;
	ManagerOfManagers::GetInstance().getRender().loadScore(score);
}

void Interface::subScore(int sub) {
	score -= sub;
	ManagerOfManagers::GetInstance().getRender().loadScore(score);
}
