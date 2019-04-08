#pragma once
#include "GameObject.h"
#include <list>

using namespace std;

class GameManager;

class GameState //Base class for all states, similar to the ones used last quarter in TPV
{
protected:
	GameManager* manager;
public:
	list<GameObject*> stage;
	list<GameObject*>stage2;
	GameState(GameManager* g);
	virtual ~GameState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);

	virtual void updateResolution();
};

