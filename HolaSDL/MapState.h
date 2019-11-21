#pragma once
#include "GameState.h"

#include "ExtraMenu.h"
#include "EmptyObject.h"
#include "PanelMap.h"
#include <iostream>
#include <fstream>
#include <utility>
#include "checkML.h"

using namespace std;

//The main map's state

class MapState : public GameState //main class for menus
{
public:

	MapState(GameManager* g);
	~MapState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync);
	pair <EmptyObject, PanelMap> buttons[5];

private:

	int index = 0;
	int virtualIndex = 0;
	int min = 0;
	int max = 4;
	
	bool activeLevels[5] = {true, false, false, false, false };
	int levelOrder[5] = { 0, 2, 3, 1, 4 };

	bool keyup = true;

	void loadGame();

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;
	SDL_GameController* controller2 = NULL;

	EmptyObject* fondo__;
	EmptyObject* moreLvls_;
	EmptyObject* selector_;
	EmptyObject* selectorKeys_;
	EmptyObject* selector2_;
	EmptyObject* selectorKeys2_;

	void unlockLevel(int lvl);
	void lockLevels();
	void createMainButtons();
	void nextButton();
	void backButton();
	void changeControllerP1(bool raise);
	void changeControllerP2(bool raise);
	void changeSelectors();

};