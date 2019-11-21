#pragma once
#include "GameObject.h"
#include "EmptyObject.h"
#include "GameState.h"
#include "Timer.h"
#include "Background.h"
#include <list>
#include "checkML.h"
#include "TextObject.h"
#include "ExtraSong.h"
#include <fstream>
#include <iostream>

//State used to display a menu for selecting the extra levels made for Guerrilla/FIMP

class PlayState;

enum CurrentSinger {
	ROBOT, PAPITO, EMINEM, CORPSE, ALIEN, NESS, SHREK, HONK,
};

class ExtraMenu: public GameState
{
private:
	Timer* timer;
	SDL_GameController* controller = NULL;
	SDL_GameController* controller2 = NULL;
	double distanceHand;
	PlayState* level;

	EmptyObject* bg;
	EmptyObject* hand;
	EmptyObject* switchPlayers;
	EmptyObject* select;
	EmptyObject* arrowL;
	EmptyObject* arrowR;
	GameObject* character; //600x300?
	//agreTextObject* description; //600x600?
	EmptyObject* descriptionBox; //600x600?
	EmptyObject* selector_;
	EmptyObject* selectorKeys_;
	EmptyObject* selector2_;
	EmptyObject* selectorKeys2_;

	int currentSinger = ROBOT;

	vector<TextObject*> description;
	vector<vector<ExtraSong*>> songList;

	bool onePlayer = true;
	int posHand = 0;

	bool optionsOpen = false;

	void selectionUp();
	void selectionDown();
	void selectionLeft();
	void selectionRight();
	void resumeSong() {};
	void toggleOptions() {};
	void restartSong() {};
	void init();
	void initSongs();
	void cleanStuff();
	void exitSong() {};
	void updateSinger();
	void changeControllerP1(bool raise);
	void changeControllerP2(bool raise);
	void changeSelectors();

public:
	ExtraMenu(GameManager* game);
	~ExtraMenu();

	virtual bool handleEvent(Uint32 time,  SDL_Event event);
	virtual void update(Uint32 time) {};
	virtual void render(Uint32 time, bool beatSync = false);
};

