#pragma once
#include "GameObject.h"
#include "FondoBarra.h"
class BarrasHUD : public GameObject
{
protected:
	bool findeNivel;
	Texture* texture;
	FondoBarra* bar;
public:

	BarrasHUD(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel, FondoBarra* fondo);
	void GetFrameBarra();
	virtual ~BarrasHUD();
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);

private:
};

