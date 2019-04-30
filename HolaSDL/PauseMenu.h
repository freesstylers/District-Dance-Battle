#pragma once
#include "GameObject.h"
#include "EmptyObject.h"
#include "TimerNoSingleton.h"
#include "TextObject.h"
#include <list>
#include <string>

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
	EmptyObject* music;
	EmptyObject* musicSelect;
	EmptyObject* sounds;
	EmptyObject* soundsSelect;
	EmptyObject* controls;
	EmptyObject* controlsSelect;
	EmptyObject* op_exit;

	EmptyObject* selection;

	TextObject* musicTxt;
	TextObject* soundTxt;
	TextObject* controlTxt;

	vector<EmptyObject*> menuButtons;
	vector<EmptyObject*> optionsButtons;

	int selectedButton = 0;
	bool optionsOpen = false;

	void resumeSong();
	void toggleOptions();
	void restartSong();
	void exitSong();
	void updateMusic(bool raise);
	void updateSound(bool raise);
	void updateControls();
	void updateTxt();




public:
	PauseMenu(SDLGame* game, PlayState* ps);
	~PauseMenu();

	void activate();


	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time, bool beatSync = false);
	virtual void updateResolution(double wScale, double hScale);
};