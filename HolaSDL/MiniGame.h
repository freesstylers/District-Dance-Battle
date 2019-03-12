#pragma once
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "GameObject.h"
#include "Timer.h"
#include "TimerNoSingleton.h"
#include "Note.h"
#include "Feedback.h"





using namespace std;
class PlayState;
class GameManager;
class LevelInputManager;
class MiniGame
{
protected:
	SDL_GameController* controller = NULL;
	bool keyup = true;
	bool keyup2 = true;
	bool failed = false;
	string level;
	GameManager* manager;
	PlayState* playS;

	int noteAmount = 15;
	int maxNotes = noteAmount;

	TimerNoSingleton* timer;


public:
	bool getFailed() { return failed; };
	MiniGame(GameManager* g, PlayState* p );
	~MiniGame() { delete timer; };
	std::list<Note*> levelButtons_;
	std::list<Note*> screenButtons_;
	void generateButtons();
	void render(Uint32 time);
	virtual void update(Uint32 time); 
	void createList();
	void deleteList();
	Feedback* fback;
	//list<Note*> getList() { return flechas; };

};