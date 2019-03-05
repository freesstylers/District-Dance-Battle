#pragma once
#include "GameObject.h"
class Squares : public GameObject
{
public:
	Squares();
	Squares(SDLGame* game, double width, double height, Vector2D pos);
	virtual ~Squares();
	virtual void update(Uint32 time){}
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return true; }
};

