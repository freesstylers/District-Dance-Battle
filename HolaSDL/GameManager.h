#pragma once
#include "GameStateMachine.h"
#include "SDLGame.h"
#include "PlayState.h"

class GameManager: public SDLGame
{
public:
	GameManager();
	~GameManager();
	void run();
	void update(Uint32 time);
	void handleEvent(Uint32 time);
	void render(Uint32 time);
	bool checkExit();
	virtual void start(); // start the game
	virtual void stop();  // stop the game
protected:
	GameStateMachine* machine;
	bool exit_;
private:
	const static int _WINDOW_WIDTH_ = 800;
	const static int _WINDOW_HEIGHT_ = 600;
};

