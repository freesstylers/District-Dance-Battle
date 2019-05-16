#pragma once
#include "GameStateMachine.h"
#include "SDLGame.h"
#include "TutorialState.h"
#include "MapState.h"
#include "EndState.h"
#include "MainMenuState.h"
#include "DialogState.h"
#include "checkML.h"

//Manager for the game's states, global variables, window, etc.

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
	bool exit_;
	virtual void start(); // start the game
	virtual void stop();  // stop the game
	GameStateMachine* getMachine();
	void tick();
	bool mainmenu = true;
	
protected:
	GameStateMachine* machine;
	
	
private:
	uint32_t last_tick_time = 0;

	const static int _WINDOW_WIDTH_ = 1280;
	const static int _WINDOW_HEIGHT_ = 720;
};

