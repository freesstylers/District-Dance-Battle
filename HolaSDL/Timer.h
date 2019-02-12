#pragma once
#include <SDL.h>
class Timer
{
private:
	static Timer* _Instance;
	unsigned int _StartTicks;
	unsigned int _ElapsedTicks;
	float _DeltaTime;
	float _TimeScale;

	Timer();
	~Timer();
public:


	static Timer* Instance();
	static void Release();

	void Reset();
	float DeltaTime();

	void TimeScale(float t);
	float TimeScale();

	void Update();
};