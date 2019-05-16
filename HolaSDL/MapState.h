#pragma once
#include "GameState.h"
#include "Button.h"
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
	int min = 0;
	int max = 4;
	
	bool activeLevels[5] = {true, false, false, false, false };

	bool keyup = true;

	void loadGame();

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;

	EmptyObject* fondo__;
	EmptyObject* moreLvls_;

	void unlockLevel(int lvl);
	void lockLevels();
	void createMainButtons();
	void nextButton();
	void backButton();

};