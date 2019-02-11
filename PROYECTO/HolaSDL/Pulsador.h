#pragma once
#include "GameObject.h"

/*Esta clase es la parte en la que se comprueba si la flecha esta dentro de los margenes de miss, bad, good, perfect*/
class Pulsador :
	public GameObject
{
public:
	Pulsador();
	virtual ~Pulsador();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

	int checkAccuracy(double xPos);
};

