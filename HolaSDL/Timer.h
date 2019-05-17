#pragma once
#include <SDL.h>
#include "checkML.h"

//Timer used for note's tempo 
class Timer
{
private:
	unsigned int _StartTicks;
	unsigned int _ElapsedTicks;
	unsigned int offset;
	float _DeltaTime;
	float _TimeScale;
	float _lastItTimer;

public:
	Timer();
	~Timer();

	//Resets the timers ticks
	void Reset();
	float DeltaTime();

	void TimeScale(float t);
	float TimeScale();

	void setLastItTime(double t) { _lastItTimer = t; }
	double getLastTIme() { return _lastItTimer; }
	void Update();

	void setOffset(unsigned int time) { offset = time; }
};

