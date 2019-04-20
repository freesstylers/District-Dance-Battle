#pragma once
#include "GameState.h"
#include "Button.h"
#include "EmptyObject.h"
#include "PanelMap.h"
#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

class MapState : public GameState //main class for menus
{
public:

	MapState(GameManager* g);
	~MapState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync);
	pair <EmptyObject, PanelMap> buttons[6];

private:
	
	bool activeLevels[5];

	int index = 0;
	int min = 0;
	int max = 5;

	void play(int lvl_);
	void loadGame();
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;

	EmptyObject* fondo__;
	EmptyObject* moreLvls_;

	void createMainButtons();
	void nextButton();
	void backButton();

	void unlockLevels();

};