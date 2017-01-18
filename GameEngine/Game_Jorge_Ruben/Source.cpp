#include "ManagerOfManagers.h"
#include <iostream>
#include <vector>

void wrap(Object* obj) {
	if (obj->transform->x > 860) {
		obj->transform->x = -60;
	}
	if (obj->transform->y > 660) {
		obj->transform->y = -60;
	}
	if (obj->transform->x < -60) {
		obj->transform->x = 860;
	}
	if (obj->transform->y < -60) {
		obj->transform->y = 660;
	}
}
bool checkCollision(Object* obj1, Object* obj2) {

	return false;
}

const float        UPDATE_INTERVAL = 1000.0f / 60.0f;
int main(int argc, char* args[])
{
	ManagerOfManagers::CreateSingleton();

	ManagerOfManagers::GetInstance().initialice();

	Object* background = new Object;
	background->init();
	background->transform->x = 0;
	background->transform->y = 0;
	background->image->loadSprite("Images/background.png");

	Object* ship = new Object;
	ship->init();
	ship->transform->x = 0;
	ship->transform->y = 500;
	ship->sound->loadEffect("Sound/FX-Lazer294.wav");
	ship->image->loadSprite("Images/thrust_ship.png");

	Object* music = new Object;
	music->init();
	music->transform->x = 0;
	music->transform->y = 0;
	music->sound->loadMusic("Sound/La_cabalgata_de_las_Valkirias_-_Richard_Wagner.wav");



	//A partir de aqui se renderizara en el orden en que lo introduzcas
	ManagerOfManagers::GetInstance().getObjects().newObject(background);
	ManagerOfManagers::GetInstance().getObjects().newObject(music);
	ManagerOfManagers::GetInstance().getObjects().newObject(ship);

	music->sound->playMusic();

	std::vector<Object*> bullets;
	std::vector<Object*> asteroids;

	//Vidas
	std::vector<Object*> vidas;
	Object* aux = new Object;
	aux->init();
	aux->transform->x = 20;
	aux->transform->y = 20;
	aux->image->loadSprite("Images/heart.png");
	vidas.push_back(aux);
	ManagerOfManagers::GetInstance().getObjects().newObject(aux);

	aux = new Object;
	aux->init();
	aux->transform->x = 40;
	aux->transform->y = 20;
	aux->image->loadSprite("Images/heart.png");
	vidas.push_back(aux);
	ManagerOfManagers::GetInstance().getObjects().newObject(aux);

	aux = new Object;
	aux->init();
	aux->transform->x = 60;
	aux->transform->y = 20;
	aux->image->loadSprite("Images/heart.png");
	vidas.push_back(aux);
	ManagerOfManagers::GetInstance().getObjects().newObject(aux);

	int timerNewAsteroid = 0;
	int score = 0;
	int timeShoot = 30;

	//While application is running
	while (!ManagerOfManagers::GetInstance().getInput().quit)
	{
		int timeElapsed = 0;
		ManagerOfManagers::GetInstance().update();

		// Update logic
		if (ManagerOfManagers::GetInstance().getTime().newFrame()) {
			//Creacion Asteroides
			timerNewAsteroid++;
			if (timerNewAsteroid > 30) {
				timerNewAsteroid = 0;
				Object* asteroid = new Object;
				asteroid->init();
				asteroid->transform->x = rand() % 800;
				asteroid->transform->y = -40;
				asteroid->image->loadSprite("Images/asteroids_big.png");
				asteroids.push_back(asteroid);
				ManagerOfManagers::GetInstance().getObjects().newObject(asteroid);
			}
			//Movimiento balas
			for (unsigned i = 0; i < bullets.size(); i++) {
				bullets.at(i)->transform->y -= 5;
				if (bullets.at(i)->transform->y < -10) {
					ManagerOfManagers::GetInstance().getObjects().deleteObject(bullets.at(i));
					bullets.erase(bullets.begin() + i);
				}
			}
			//Movimeinto asteroides
			for (unsigned i = 0; i < asteroids.size(); i++) {
				asteroids.at(i)->transform->x += 2;
				asteroids.at(i)->transform->y += 2;
				asteroids.at(i)->transform->angle += 1;
				wrap(asteroids.at(i));
			}

			//Movimiento nave
			if (ManagerOfManagers::GetInstance().getInput().mKeys[SDLK_LEFT]) {
				ship->transform->x -= 10;
			}
			if (ManagerOfManagers::GetInstance().getInput().mKeys[SDLK_RIGHT]) {
				ship->transform->x += 10;
			}
			wrap(ship);
			//Comprobación colision
			for (unsigned i = 0; i < asteroids.size(); i++) {
				if (ManagerOfManagers::GetInstance().getObjects().checkCollision(ship, asteroids.at(i))) {
					ManagerOfManagers::GetInstance().getObjects().deleteObject(asteroids.at(i));
					asteroids.erase(asteroids.begin() + i);
					Object* aux= vidas.back();
					ManagerOfManagers::GetInstance().getObjects().deleteObject(aux);
					vidas.pop_back();
				}
			}
			//Comprobacion colison balas asteroide
			for (unsigned i = 0; i < bullets.size(); i++) {
				for (unsigned d = 0; d < asteroids.size(); d++) {
					if (ManagerOfManagers::GetInstance().getObjects().checkCollision(bullets.at(i), asteroids.at(d))) {
						ManagerOfManagers::GetInstance().getObjects().deleteObject(bullets.at(i));
						bullets.erase(bullets.begin() + i);
						ManagerOfManagers::GetInstance().getObjects().deleteObject(asteroids.at(d));
						asteroids.erase(asteroids.begin() + d);
						score++;
						ManagerOfManagers::GetInstance().getRender().loadScore(score);
						break;
					}
				}
			}

			//Creación de balas
			timeShoot++;
			if (ManagerOfManagers::GetInstance().getInput().mKeys[SDLK_SPACE] && timeShoot > 30) {
				Object* aux = new Object;
				aux->init();
				aux->transform->x = ship->transform->x + (ship->image->sprite->w) / 2;
				aux->transform->y = ship->transform->y - 5;
				aux->image->loadSprite("Images/bullet.png");
				ship->sound->playEffect();
				timeShoot = 0;	
				bullets.push_back(aux);
				ManagerOfManagers::GetInstance().getObjects().newObject(aux);
			}
			if (vidas.size() == 0) {
				ManagerOfManagers::GetInstance().getInput().quit = true;
			}
			ManagerOfManagers::GetInstance().getRender().clearScreen();
		}
	}

	ManagerOfManagers::GetInstance().close();

	return 0;
}