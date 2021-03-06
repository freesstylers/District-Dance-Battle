#pragma once
#include "GameObject.h"
#include "checkML.h"

//Is the point where the notes has to be pressed
class Point : public GameObject
{
private:
	SDL_GameController* controller;
	bool side_;
	int controllerMode = 0;
public:
	void setControllerMode(int controller) { controllerMode = controller; }
	Point(SDLGame* game, double width, double height, Vector2D pos, SDL_GameController* contr, bool side, int player);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time) {};
	~Point();
};

