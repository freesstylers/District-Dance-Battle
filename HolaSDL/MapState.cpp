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
