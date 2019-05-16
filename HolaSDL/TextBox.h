#pragma once
#include "GameObject.h"
#include "checkML.h"

//Box where the character talks. It change the text, the character's face and the box colour
class TextBox : public GameObject
{
public:
	TextBox(SDLGame* game, double width, double height, Vector2D pos, int i);
	virtual void update(Uint32 time) {};
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
};

