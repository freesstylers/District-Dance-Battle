#pragma once
#include "GameObject.h"
class Perico: public GameObject
{
public:
	Perico(SDLGame* game, double width, double height, Vector2D pos);
	virtual ~Perico();
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event); 
};

