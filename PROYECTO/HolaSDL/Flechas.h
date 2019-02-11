#pragma once
#include "GameObject.h"
class Flechas: public GameObject
{
protected:
	Texture* texture;
	SDL_Keycode key;
public:
	Flechas();
	Flechas(SDL_Keycode key, SDLGame* game, double width, double height, Vector2D pos, Vector2D vel);
	virtual ~Flechas();
	virtual void handleInput(Uint32 time, const SDL_Event& event); //Puede que no lo necesitemos si se lleva las pulsaciones desde pulsador
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

