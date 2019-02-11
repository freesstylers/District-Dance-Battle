#include "MapState.h"



MapState::MapState(Game* g) : GameState( g)
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
