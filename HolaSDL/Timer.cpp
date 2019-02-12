#include "Timer.h"

Timer* Timer::_Instance = NULL;

Timer* Timer::Instance()
{
	if (_Instance == NULL)
		_Instance = new Timer();
	return _Instance;
}

void Timer::Release()
{
	delete _Instance;
	_Instance = NULL;
}
Timer::Timer()
{
	Reset();
	_TimeScale = 1.0f;
}


Timer::~Timer()
{
}

void Timer::Reset()
{
	_StartTicks = SDL_GetTicks();
	_ElapsedTicks = 0;
	_DeltaTime = 0.0f;
}

float Timer::DeltaTime()
{
	return _DeltaTime;
}

void Timer::TimeScale(float t)
{
	_TimeScale = t;
}

float Timer::TimeScale()
{
	return _TimeScale;
}

void Timer::Update()
{
	_ElapsedTicks = SDL_GetTicks() - _StartTicks;
	_DeltaTime = _ElapsedTicks * 0.001f;

}