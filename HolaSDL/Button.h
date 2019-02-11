#pragma once
#include "GameObject.h"
class Button :
	public GameObject
{
public:
	Button();
	virtual ~Button();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

