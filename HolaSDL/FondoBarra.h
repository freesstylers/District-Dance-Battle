#pragma once
#include "GameObject.h"
class FondoBarra : public GameObject
{
private:
	Texture*texture;
	double vel_;
public:
	FondoBarra(SDLGame* game, double width, double height, Vector2D pos, double vel);
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual ~FondoBarra();
};

