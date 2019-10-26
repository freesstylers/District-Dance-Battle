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

//State used to display a menu for selecting the extra levels made for Guerrilla/FIMP

class PlayState;

enum CurrentSinger {
	ROBOT, PAPITO, EMINEM, CORPSE, ALIEN, NESS, SHREK,
};

class ExtraMenu: public GameState
{
private:
	Timer* timer;
	SDL_GameController* controller = NULL;
	double distanceHand;
	PlayState* level;

	EmptyObject* bg;
	EmptyObject* hand;
	EmptyObject* switchPlayers;
	EmptyObject* select;
	GameObject* character; //600x300?
	TextObject* description; //600x600?
	EmptyObject* descriptionBox; //600x600?

	CurrentSinger currentSinger = ROBOT;

	vector<ExtraSong*> songList;

	bool onePlayer = true;
	int posHand;

	bool optionsOpen = false;

	void selectionUp();
	void selectionDown();
	void resumeSong() {};
	void toggleOptions() {};
	void restartSong() {};
	void init();
	void initSongs();
	void exitSong() {};

public:
	ExtraMenu(GameManager* game);
	~ExtraMenu();

	virtual bool handleEvent(Uint32 time,  SDL_Event event);
	virtual void update(Uint32 time) {};
	virtual void render(Uint32 time, bool beatSync = false);
};

