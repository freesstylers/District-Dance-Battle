#pragma once
#include "GameObject.h"
#include "Timer.h"
#include "checkML.h"

//Class used for all the in-game character sprites, handles how they should be animated and when they should change their animations

class Character: public GameObject
{
private:

	Timer* timer;
	Timer* timerAlien;	//since the alien character needs to change sprites half-way through the song, there's an extra timer just to handle that
	bool isAlien = false;
	int firstAnim = -1;
	int secondAnim = -1;
	bool dancing = false;

public:
	Character(SDLGame* game, double width, double height, Vector2D pos, int i);
	virtual ~Character();
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
};

