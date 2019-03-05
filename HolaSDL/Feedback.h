#pragma once
#include "GameObject.h"
#include "Timer.h"

class Feedback :
	public GameObject
{
private:
	Timer* timer;
	virtual void changeAnimation(int animationTag);
public:
	Feedback(SDLGame* game, double width, double height, Vector2D pos);
	virtual ~Feedback();
	virtual void render(Uint32 time, bool beatSync);
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; }
};

