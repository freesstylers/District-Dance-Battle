#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "checkML.h"

//simple class used to handle the game's bpm

using namespace std;
class BeatHandler
{
protected:

	double bmp;
	double beatTime;
public:
	BeatHandler();
 	BeatHandler(int bmp) :bmp(bmp) {beatTime = 60000 / bmp;};
	~BeatHandler();

	//This method converts bpm into seconds per beat
	double getBeatTime() { 
		double ms;
		ms = 60000.0 / bmp;
		return ms; 
	};

};