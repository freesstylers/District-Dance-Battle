#pragma once
#include "GameObject.h"
class Point : public GameObject
{
private:
	Texture* texture;
public:
	Point();
	Point(SDLGame* game, double width, double height, Vector2D pos);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false;  };//Puede que no lo necesitemos si se lleva las pulsaciones desde pulsador
	virtual void update(Uint32 time) {};
	virtual void render(Uint32 time);
	~Point();
};

