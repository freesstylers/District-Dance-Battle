#pragma once
#include <SDL.h>
class Timer
{
private:
	static Timer* _Instance;
	unsigned int _StartTicks;
	unsigned int _ElapsedTicks;
	unsigned int offset;
	float _DeltaTime;
	float _TimeScale;
	float _lastItTimer;
	Timer();
	~Timer();

public:


	static Timer* Instance();
	static void Release();

	void Reset();
	float DeltaTime();

	void TimeScale(float t);
	float TimeScale();
	void setLastItTime(double t) { _lastItTimer = t; }
	double getLastTIme() { return _lastItTimer; }
	void Update();

	void setOffset(unsigned int time) { offset = time; }
};