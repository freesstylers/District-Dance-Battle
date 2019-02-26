#pragma once
#include "GameObject.h"

class GameManager;

class Flechas: public GameObject
{
protected:
	//Texture* texture;
	SDL_GameControllerButton key;
public:
	Flechas();
	Flechas(SDL_GameControllerButton key, SDLGame* game, double width, double height, Vector2D pos, Vector2D vel);
	virtual ~Flechas();
	virtual bool handleInput(Uint32 time, const SDL_Event& event); //Puede que no lo necesitemos si se lleva las pulsaciones desde pulsador
	virtual void update(Uint32 time);
	SDL_GameControllerButton getKey() { return key; };
};

