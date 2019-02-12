#pragma once
#include "MapState.h"

class CutSceneState: public MapState //Hereda de MapState por similitud de funcionalidad, render lo hereda de GameState, mantiene update y handleEvent independientes
{
public:
	CutSceneState(GameManager* g);
	~CutSceneState();
	virtual void update();
	virtual bool handleEvent(SDL_Event e);
};

