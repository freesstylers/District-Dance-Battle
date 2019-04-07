#pragma once
#include "GameState.h"
#include "Button.h"
#include "EmptyObject.h"
#include "PanelMap.h"
#include <iostream>
#include <sstream>
#include <utility> 
#include "PanelMap.h"

using namespace std;

class MapState : public GameState //main class for menus
{
public:

	MapState(GameManager* g);
	~MapState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync);

private:
	pair <EmptyObject, PanelMap> buttons[5];
	bool activeLevels[5];

	int index = 0;
	int min = 0;
	int max = 4;

	void play(int lvl_);
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;

	EmptyObject fondo__;

	void createMainButtons();
	void nextButton();
	void backButton();

};