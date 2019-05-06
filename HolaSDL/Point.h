#pragma once
#include "GameObject.h"
#include "checkML.h"

class Point : public GameObject
{
private:
	SDL_GameController* controller;
	bool side_;
public:
	
	Point(SDLGame* game, double width, double height, Vector2D pos, SDL_GameController* contr, bool side);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time) {};
	~Point();
};

