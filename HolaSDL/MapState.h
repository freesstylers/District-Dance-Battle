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

//Estado del juego del mapa principañ

class MapState : public GameState //main class for menus
{
public:

	MapState(GameManager* g);
	~MapState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync);
	pair <EmptyObject, PanelMap> buttons[5];

private:
	
	bool activeLevels[5] = {true, true, false, false, false }; // Array de niveles activos cuando empieza la partida por primera vez

	int index = 0;
	int min = 0;
	int max = 4;

	void play(int lvl_);
	void loadGame();
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;

	EmptyObject* fondo__;
	EmptyObject* moreLvls_;

	void unlockLevel(int lvl);
	void createMainButtons();
	void nextButton();
	void backButton();

	void unlockLevels();

};