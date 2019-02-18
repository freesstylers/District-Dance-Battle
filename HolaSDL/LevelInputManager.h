#pragma once

#include "GameObject.h"

class DemoGame;

class LevelInputManager
{
public:
	LevelInputManager(DemoGame* l);
	~LevelInputManager();

	void handleInput(Uint32 time, const SDL_Event& event);

private:

	bool keyup = true;
	DemoGame* level;

};

