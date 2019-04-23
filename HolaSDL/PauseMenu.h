#pragma once
#include "GameObject.h"
#include "EmptyObject.h"
#include "TimerNoSingleton.h"
#include <list>

class PlayState;

class PauseMenu :
	public GameObject
{
private:
	TimerNoSingleton* timer;
	SDL_GameController* controller = NULL;

	PlayState* level;

	EmptyObject* bg;
	EmptyObject* options;
	EmptyObject* resume;
	EmptyObject* restart;
	EmptyObject* exit;

	EmptyObject* op_bg;
	EmptyObject* op_exit;
	EmptyObject* music;
	EmptyObject* sounds;
	EmptyObject* scale;

	EmptyObject* selection;

	vector<EmptyObject*> menuButtons;
	vector<EmptyObject*> optionsButtons;

	int selectedButton = 0;
	bool optionsOpen = false;

	void resumeSong();
	void toggleOptions();
	void restartSong();
	void exitSong();



public:
	PauseMenu(SDLGame* game, PlayState* ps);
	~PauseMenu();

	void activate();


	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time, bool beatSync = false);
	virtual void updateResolution(double wScale, double hScale);
};