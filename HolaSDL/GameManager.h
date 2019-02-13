#pragma once
#include "GameStateMachine.h"
#include "SDLGame.h"

class GameManager
{
public:
	GameManager(SDLGame* game);
	~GameManager();
	void run();
	void update(Uint32 time);
	void handleEvent(Uint32 time);
	void render(Uint32 time);
	void exit();
	bool checkExit();
	SDLGame* getGame();
protected:
	GameStateMachine* machine;
	bool exit_;
	SDLGame* game;
};

