#pragma once
#include "GameObject.h"
#include "EmptyObject.h"
#include "GameState.h"
#include "TimerNoSingleton.h"
#include "Background.h"
#include <list>
#include "checkML.h"

//El estado donde aparecen los créditos

class Credits: public GameState
{
private:
	SDL_GameController* controller = NULL;

	EmptyObject* bg;

	bool optionsOpen = false;

public:
	Credits(GameManager* game);
	virtual bool handleEvent(Uint32 time, SDL_Event event);
	virtual void update(Uint32 time) {};
	virtual void render(Uint32 time, bool beatSync = false);
	void init();
	~Credits();
};

