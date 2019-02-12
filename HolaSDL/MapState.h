#pragma once
#include "GameState.h"

class MapState: public GameState //Clase que muestra el mapa y ofrece interaccion básica, render lo hereda de GameState, mantiene update y handleEvent independientes
{
public:
	MapState(GameManager* g);
	~MapState();
	virtual void update();
	virtual bool handleEvent(SDL_Event e);
};

