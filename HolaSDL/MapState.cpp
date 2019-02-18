#include "MapState.h"
#include "GameManager.h"


MapState::MapState(GameManager* g) : GameState( g)
{
}


MapState::~MapState()
{
}

void MapState::update()
{
}

bool MapState::handleEvent(SDL_Event e)
{
	return false;
}

//////////////////////////////////////////////////////////////////

/*

//Cargar zona (que será un PlayState con parámetros)

//Lanzar menús

//Elegir zona

//Menu de guardar/cargar partida/ajustes/salir

*/
