#pragma once
#include "GameObject.h"
#include "EmptyObject.h"
#include "Timer.h"
#include "TextObject.h"
#include <list>
#include <string>
#include "checkML.h"

//Pause menu during levels

class TutorialState;
class PlayState;

class PauseMenu :
	public GameObject
{
private:
	int controllerMode;

	Timer* timer;
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
	EmptyObject* controls2;
	EmptyObject* controlsSelect2;
	EmptyObject* op_exit;

	EmptyObject* selection;

	TextObject* musicTxt;
	TextObject* soundTxt;
	TextObject* controlTxt;
	TextObject* control2Txt;

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
	
	void updateTxt();
	int P1Controller;
	int P2Controller;

public:
	PauseMenu(SDLGame* game, PlayState* ps, int controllerMode);
	~PauseMenu();

	void activate();
	void updateControlsP1(bool raise);
	void updateControlsP2(bool raise);

	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time) {};
	virtual void render(Uint32 time, bool beatSync = false);
};