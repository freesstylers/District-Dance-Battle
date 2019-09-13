#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "GameState.h"
#include "Timer.h"
#include "BeatHandler.h"
#include "PlayState.h"


class CreadorNiveles: public GameState
{
public:
	CreadorNiveles(GameManager* g);
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false) {}
private:
	vector<int> leftNotes;
	vector<int> rightNotes;
	double msDiff = 0.0;
	int time, bpm, snumber, beatsNumber, restBeats;
	string sname; //-, -, song number
	Timer* timer; // song name
	BeatHandler* bh;
	SDL_GameController* controller = NULL;
	bool start = true;
	bool inTimeL = true;
	bool inTimeR = true;
	int L = 0; 
	int R = 0;
	bool bPressed = false;
	bool aPressed = false;
	double medioBeat;

	void finish();
	int leftControl();
	int rightControl();

};

