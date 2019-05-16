#pragma once
#include "GameObject.h"
#include <list>
#include "checkML.h"

//base class for the game's different states

using namespace std;

class GameManager;

class GameState
{
protected:
	GameManager* manager;
public:
	list<GameObject*> stage;
	GameState(GameManager* g);
	virtual ~GameState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);

};

