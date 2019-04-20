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
#include "TextObject.h"

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
	bool end = false;
	bool failed = false;
	string level;
	GameManager* manager;
	PlayState* playS;
	TimerNoSingleton* timer;
	TextObject* Aviso;

	int currentMinigameScore;
	int noteAmount;
	int maxNotes;


public:
	MiniGame(GameManager* g, PlayState* p );
	~MiniGame() { };
	virtual void render(Uint32 time);
	virtual void update(Uint32 time); 
	virtual void handleInput(Uint32 time, SDL_Event e);
	bool getFailed() { return failed; };
	virtual void createList();
	virtual void deleteList();
	virtual void resetMinigame() { end = false; };
	virtual bool getEnd() { return end; };
	int getAccuracy() { if (currentMinigameScore == noteAmount) return 1; else if (currentMinigameScore >= noteAmount / 2) return 2; else return 0; }

	std::list<Note*> screenButtons_;
	std::list<Note*> levelButtons_;

	virtual void updateResolution(double wScale, double hScale);

	Feedback* fback;
};