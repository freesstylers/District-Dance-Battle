#pragma once

#include "ScoreBar.h"
#include "GameObject.h"
#include "checkML.h"

class PlayerPack;
class PlayState;

//this class handles every input related to the level's notes, how accurately they're hit, and also opens the pause menu

class LevelInputManager
{
public:
	LevelInputManager(PlayState* l, PlayerPack* pl, int numctrl, bool keyboard);
	~LevelInputManager();

	bool handleInput(Uint32 time, const SDL_Event& event);

	bool getFailed() { return failed; }

	void blockPause(int time) { blockpause = time; };

	void setMinigameActive(bool active) { 
		minigameActive = active;
	}
	SDL_GameController* getController(){ return controller; }
	int numFailed = 0;

private:
	int numctrl_;
	int blockpause = 0;
	bool failed = false;
	bool minigameActive = false;
	const Uint8 *keystates; //esto no se que hace, se puede quitar?
	bool keyup = true;
	bool keyup2 = true;
	bool pressed = false;
	PlayState* level;
	PlayerPack* player;
	SDL_GameController* controller = NULL;
	bool keyboard_;
};

