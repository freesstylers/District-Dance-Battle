#pragma once

#include "GameObject.h"

class PlayState;

class LevelInputManager
{
public:
	LevelInputManager(PlayState* l);
	~LevelInputManager();

	void handleInput(Uint32 time, const SDL_Event& event);

private:

	bool keyup = true;
	PlayState* level;

};

