#pragma once
#include "GameObject.h"
#include <list>

using namespace std;

class GameManager;

class GameState //Clase base para todos los estados, mismo funcionamiento que las practicas del primer cuatrimestre de TPV
{
protected:
	list<GameObject*> stage;
	GameManager* manager;
public:
	GameState(GameManager* g);
	virtual ~GameState();
	virtual void update();
	virtual bool handleEvent(SDL_Event e);
	virtual void render(Uint32 time);
};

