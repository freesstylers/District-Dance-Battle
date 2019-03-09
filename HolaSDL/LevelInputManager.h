#pragma once
#include "MiniGame.h"
#include "BarraPuntos.h"
#include "GameObject.h"

class PlayState;

class LevelInputManager
{
public:
	LevelInputManager(PlayState* l, int numctrl);
	~LevelInputManager();

	void handleInput(Uint32 time, const SDL_Event& event);

	bool getFallado() { return fallado; }

	void update();

	void setMinigameActive(bool active) { 
		minigameActive = active;
	}
private:
	int numctrl_;
	bool fallado = false;
	bool minigameActive = false;
	const Uint8 *keystates;
	bool keyup = true;
	bool keyup2 = true;
	PlayState* level;
	SDL_GameController* controller = NULL;
};

