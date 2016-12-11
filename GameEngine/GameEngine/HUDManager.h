#pragma once
#include "Singleton.h"
class HUDManager : public Singleton <HUDManager>
{
	friend class Singleton <HUDManager>;
public:
	void drawText(); //podemos dibujar cosas como BOOM cuando exploten los asteroides o añadir dialogos con los bosses
	void drawHud();  //dibuja la interfaz basica del juego
	void drawLives(); //dibuja las vidas, posible uso para updates, CUANDO MUERES SALDRA UNA ANIMACIÓN DE GAME OVER HE IRAS DIRECTAMENTE AL SCORE
	void drawScore(); //dibuja el score, posible uso para updates
	void drawPause(); //dibuja los botones y temas que utilizemos cuando pausemos el juego
	void drawStartScreen(); //dibuja la pantalla inicial del juego
	void drawScoreScreen(); //dibuja la pantalla de score del juego

private:
	HUDManager();
	~HUDManager();
};

