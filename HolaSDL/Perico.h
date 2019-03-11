#pragma once
#include "GameObject.h"
class Perico: public GameObject
{
private:
	
public:
	Perico(SDLGame* game, double width, double height, Vector2D pos, int i);
	virtual ~Perico();
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event); 
};

