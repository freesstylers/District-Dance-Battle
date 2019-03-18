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
	bool keyup = true;
	bool keyup2 = true;
	bool failed = false;
	string level;
	GameManager* manager;
	PlayState* playS;
	TimerNoSingleton* timer;


public:
	MiniGame(GameManager* g, PlayState* p );
	~MiniGame() { delete timer; };
	virtual void render(Uint32 time);
	virtual void update(Uint32 time); 
	bool getFailed() { return failed; };
	virtual void createList();
	virtual void deleteList();

	std::list<Note*> screenButtons_;
	Feedback* fback;

};