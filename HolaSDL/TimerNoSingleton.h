#pragma once
#include <SDL.h>
class TimerNoSingleton
{
private:
	unsigned int _StartTicks;
	unsigned int _ElapsedTicks;
	float _DeltaTime;
	float _TimeScale;
	float _lastItTimer;

public:
	TimerNoSingleton();
	~TimerNoSingleton();
	void Reset();
	float DeltaTime();

	void TimeScale(float t);
	float TimeScale();
	void setLastItTime(double t) { _lastItTimer = t; }
	double getLastTIme() { return _lastItTimer; }
	void Update();
};

