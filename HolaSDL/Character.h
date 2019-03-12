#pragma once
#include "GameObject.h"
class Character: public GameObject
{
private:
	
public:
	Character(SDLGame* game, double width, double height, Vector2D pos, int i);
	virtual ~Character();
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event); 
};

