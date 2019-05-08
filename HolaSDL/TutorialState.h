#pragma once
#include "PlayState.h"
class TutorialState :
	public PlayState
{
public:
	TutorialState(GameManager* g);
	~TutorialState();


	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);

};

