#pragma once
#include "GameObject.h"
#include "EmptyObject.h"
#include "GameState.h"
#include "TimerNoSingleton.h"
#include "Background.h"
#include <list>

class PlayState;

class ExtraMenu: public GameState
{
private:
	TimerNoSingleton* timer;
	SDL_GameController* controller = NULL;
	double distanceHand;
	PlayState* level;

	EmptyObject* bg;
	EmptyObject* hand;
	EmptyObject* switchPlayers;
	EmptyObject* select;

	bool onePlayer = true;
	int posHand;

	bool optionsOpen = false;

	void selectionUp();
	void selectionDown();
	void resumeSong() {};
	void toggleOptions() {};
	void restartSong() {};
	void init();
	void exitSong() {};

public:
	ExtraMenu(GameManager* game);
	~ExtraMenu();

	virtual bool handleEvent(Uint32 time,  SDL_Event event);
	virtual void update(Uint32 time) {};
	virtual void render(Uint32 time, bool beatSync = false) ;
	virtual void updateResolution(double wScale, double hScale) {};
};

