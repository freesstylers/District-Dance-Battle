#pragma once
#include "GameObject.h"
#include <list>

using namespace std;

class GameManager;

class GameState //Clase base para todos los estados, mismo funcionamiento que las practicas del primer cuatrimestre de TPV
{
protected:
	list<GameObject*> stage;
	
public:
	GameState(GameManager* g);
	virtual ~GameState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time);
	GameManager* manager;
};

