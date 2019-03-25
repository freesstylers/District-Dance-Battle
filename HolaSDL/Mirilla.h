#pragma once
#include "GameObject.h"
#include "Note.h"

class Mirilla: public GameObject
{
public:
	Mirilla(SDLGame* game, double width, double height, Vector2D pos);
	~Mirilla();
	virtual bool handleInput(Uint32 time, const SDL_Event& event); //Puede que no lo necesitemos si se lleva las pulsaciones desde pulsador
	virtual bool handleInput(Uint32 time, const SDL_Event& event, Note* nota); //Puede que no lo necesitemos si se lleva las pulsaciones desde pulsador
	virtual void update(Uint32 time);
	SDL_GameController* controller;
	bool superpuesto = false;
};

