#pragma once

#include "GameObject.h"

class PlayState;

class LevelInputManager
{
public:
	LevelInputManager(PlayState* l, int numctrl);
	~LevelInputManager();

	void handleInput(Uint32 time, const SDL_Event& event);

private:
	int numctrl_;
	const Uint8 *keystates;
	bool keyup = true;
	bool keyup2 = true;
	PlayState* level;
	SDL_GameController* controller = NULL;
};

