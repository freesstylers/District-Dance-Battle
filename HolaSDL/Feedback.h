#pragma once
#include "GameObject.h"

class Feedback :
	public GameObject
{
public:
	Feedback(SDLGame* game, double width, double height, Vector2D pos);
	virtual ~Feedback();
	virtual void render(Uint32 time, bool beatSync);
	virtual void update(Uint32 time){}
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; }

	virtual void changeAnimation(int animationTag);
};

