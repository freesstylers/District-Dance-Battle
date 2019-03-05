#include "TimerNoSingleton.h"



TimerNoSingleton::TimerNoSingleton()
{
	Reset();
	_TimeScale = 1.0f;
}


TimerNoSingleton::~TimerNoSingleton()
{
}

void TimerNoSingleton::Reset()
{
	_StartTicks = SDL_GetTicks();
	_ElapsedTicks = 0;
	_DeltaTime = 0.0f;
}

float TimerNoSingleton::DeltaTime()
{
	return _DeltaTime;
}

void TimerNoSingleton::TimeScale(float t)
{
	_TimeScale = t;
}

float TimerNoSingleton::TimeScale()
{
	return _TimeScale;
}

void TimerNoSingleton::Update()
{
	_ElapsedTicks = SDL_GetTicks() - _StartTicks;
	_DeltaTime = _ElapsedTicks * 0.001f;

}