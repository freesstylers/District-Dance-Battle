#pragma once
#include "GameObject.h"
#include <list>

using namespace std;

class Game;

class GameState //Clase base para todos los estados, mismo funcionamiento que las practicas del primer cuatrimestre de TPV
{
protected:
	list<GameObject*> stage;
	Game* app;
public:
	GameState(Game* g);
	virtual ~GameState();
	virtual void update();
	virtual bool handleEvent(SDL_Event e);
	virtual void render();
};

