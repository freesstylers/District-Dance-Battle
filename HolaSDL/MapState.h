#pragma once
#include "GameState.h"

class MapState: public GameState //Shows the main map and offers basic interactions such as choosing a levelName or changing the options
{
public:
	MapState(GameManager* g);
	~MapState();
	virtual void update();
	virtual bool handleEvent(SDL_Event e);
};

