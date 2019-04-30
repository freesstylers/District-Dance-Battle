#pragma once
#include "GameStateMachine.h"
#include "SDLGame.h"
#include "PlayState.h"
#include "MenuState.h"
#include "MapState.h"
#include "EndState.h"
#include "DialogState.h"

class GameManager: public SDLGame
{
public:
	GameManager();
	~GameManager();
	void run();
	void update(Uint32 time);
	void handleEvent(Uint32 time);
	void render(Uint32 time);
	bool getMando() { return mandoXbox; };
	void setMando(bool xbox) { mandoXbox = xbox; };
	bool checkExit();
	bool exit_;
	virtual void start(); // start the game
	virtual void stop();  // stop the game
	GameStateMachine* getMachine();
	
protected:
	GameStateMachine* machine;
	bool mandoXbox = false;
	
private:
	const static int _WINDOW_WIDTH_ = 1280;
	const static int _WINDOW_HEIGHT_ = 720;
};

