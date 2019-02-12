#pragma once
#include "GameObject.h"
class Puntuacion: public GameObject
{
public:
	Puntuacion(SDLGame* game);
	virtual ~Puntuacion();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

