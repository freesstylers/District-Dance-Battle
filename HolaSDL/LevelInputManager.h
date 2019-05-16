#pragma once

#include "ScoreBar.h"
#include "GameObject.h"
#include "checkML.h"

class PlayerPack;
class PlayState;

class LevelInputManager
{
public:
	LevelInputManager(PlayState* l, PlayerPack* pl, int numctrl);
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
	const Uint8 *keystates;
	bool keyup = true;
	bool keyup2 = true;
	bool pressed = false;
	PlayState* level;
	PlayerPack* player;
	SDL_GameController* controller = NULL;
	
};

