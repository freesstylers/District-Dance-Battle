#pragma once
#include "GameStateMachine.h"
#include "SDLGame.h"
#include "TutorialState.h"
#include "MapState.h"
#include "EndState.h"
#include "MainMenuState.h"
#include "DialogState.h"
#include "checkML.h"

//Game manager, controla variables globales y los diferentes estados

class GameManager: public SDLGame
{
public:
	GameManager();
	~GameManager();
	void run();
	void update(Uint32 time);
	void handleEvent(Uint32 time);
	void render(Uint32 time);
	bool getController() { return isXbox; };
	void setController(bool xbox) { isXbox = xbox; };
	bool checkExit();
	bool exit_;
	virtual void start(); // start the game
	virtual void stop();  // stop the game
	GameStateMachine* getMachine();
	void tick();
	bool mainmenu = true;
	
protected:
	GameStateMachine* machine;
	bool isXbox = true;
	
	
private:
	uint32_t last_tick_time = 0;

	const static int _WINDOW_WIDTH_ = 1280;
	const static int _WINDOW_HEIGHT_ = 720;
};

