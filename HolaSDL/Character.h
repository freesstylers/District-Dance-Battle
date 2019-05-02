#pragma once
#include "GameObject.h"
#include "TimerNoSingleton.h"
class Character: public GameObject
{
private:
	TimerNoSingleton* timer;
	int firstAnim = -1;
	int secondAnim = -1;
	bool dancing = false;
public:
	Character(SDLGame* game, double width, double height, Vector2D pos, int i);
	virtual ~Character();
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
};

