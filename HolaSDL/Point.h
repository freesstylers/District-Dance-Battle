#pragma once
#include "GameObject.h"
class Point : public GameObject
{
private:
public:
	
	Point(SDLGame* game, double width, double height, Vector2D pos);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false;  };
	virtual void update(Uint32 time) {};
	~Point();
};

