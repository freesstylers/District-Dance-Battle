#pragma once
#include "GameObject.h"
class BarrasHUD : public GameObject
{
protected:
	bool findeNivel;
	Texture* texture;
public:
	BarrasHUD();
	BarrasHUD(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel);
	virtual ~BarrasHUD();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

private:
};

