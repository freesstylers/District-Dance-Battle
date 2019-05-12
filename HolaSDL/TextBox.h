#pragma once
#include "GameObject.h"
#include "checkML.h"
class TextBox : public GameObject
{
private:

public:
	TextBox(SDLGame* game, double width, double height, Vector2D pos, int i);
	virtual ~TextBox();
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
};

