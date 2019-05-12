#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "checkML.h"

//Transforma los bpm de una canción a milisegundos

using namespace std;
class BeatHandler
{
protected:
	//int currentBeats ;
	double bmp;
	double beatTime;
public:
	BeatHandler();
 	BeatHandler(int bmp) :bmp(bmp) {beatTime = 60000 / bmp;};
	~BeatHandler();
	//This methos controls when to generate notes, and at which speed
	void beatRateButton(int &currentBeats);
	//This method converts the bpm into seconds per beat
	double getBeatTime() { 
		double ms;
		ms = 60000.0 / bmp;
		return ms; 
	};

};