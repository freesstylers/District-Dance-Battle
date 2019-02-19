#pragma once
#include "GameObject.h"
class EmptyObject : public GameObject
{
protected:
	Texture*texture;
public:

	EmptyObject(SDLGame* game, double width, double height, Vector2D pos);
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void render(Uint32 time);
	virtual ~EmptyObject();
};

