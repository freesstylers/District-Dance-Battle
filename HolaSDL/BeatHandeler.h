#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class BeatHandeler
{
protected:
	//int currentBeats ;
	int bmp;
	double beatTime;
public:
	BeatHandeler();
 	BeatHandeler(int bmp) :bmp(bmp) {beatTime = 60000 / bmp;};
	~BeatHandeler();
	//This methos controls when to generate notes, and at which speed
	void beatRateButton(int &currentBeats);
	//This method converts the bpm into seconds per beat
	double getBeatTime() { return 60000/bmp; };

};