#pragma once
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Object.h"

class Interface
{
public:
	Interface();
	~Interface();
	void init(char* image, char* font, int numLives);
	void addLives();
	void subLives();
	void addScore(int add);
	void subScore(int sub);
private:
	TTF_Font*	gFont = NULL;
	//array de objetos con las vidas luego se las paso al objmanager y que las pinte
	int score = 0;
	char* pathImage;
	std::vector<Object*> lives;
};

