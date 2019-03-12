#pragma once
#include "MapState.h"

class CutSceneState: public MapState //Inherits from MapState due to similar functionality, render is inherited from GameState
{
public:
	CutSceneState(GameManager* g);
	~CutSceneState();
	virtual void update();
	virtual bool handleEvent(SDL_Event e);
};

