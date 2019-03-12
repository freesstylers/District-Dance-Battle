#pragma once
#include "GameObject.h"
#include "BarBackground.h"
class SongBar : public GameObject
{
protected:
	bool findeNivel;
	Texture* texture;
	BarBackground* bar;
public:

	SongBar(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel, BarBackground* backgroundBar);
	virtual ~SongBar();
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);

private:
};

