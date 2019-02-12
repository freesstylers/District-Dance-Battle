#pragma once
#include "GameStateMachine.h"
#include "SDLGame.h"

class GameManager
{
public:
	GameManager(SDLGame* game);
	~GameManager();
	void exit();
	bool checkExit();
	SDLGame* getGame();
protected:
	GameStateMachine* machine;
	bool exit_;
	SDLGame* game;
};

