#pragma once
#include "GameObject.h"
class Background : public GameObject
{
public:
	Background();
	Background(SDLGame* game, double width, double height, Vector2D pos, int texture);
	virtual void update(Uint32 time) {}
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return true; }
	virtual ~Background();
};

