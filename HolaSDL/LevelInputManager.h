#pragma once
#include "MiniGame.h"
#include "ScoreBar.h"
#include "GameObject.h"

class PlayerPack;
class PlayState;

class LevelInputManager
{
public:
	LevelInputManager(PlayState* l, PlayerPack* pl, int numctrl);
	~LevelInputManager();

	bool handleInput(Uint32 time, const SDL_Event& event);

	bool getFailed() { return failed; }

	void setMinigameActive(bool active) { 
		minigameActive = active;
	}
	SDL_GameController* getController(){ return controller; }
private:
	int numctrl_;
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

