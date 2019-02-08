#pragma once
#include "GameObject.h"
class Flechas: public GameObject
{
public:
	Flechas();
	virtual ~Flechas();
	virtual void handleInput(Uint32 time, const SDL_Event& event); //Puede que no lo necesitemos si se lleva las pulsaciones desde pulsador
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

