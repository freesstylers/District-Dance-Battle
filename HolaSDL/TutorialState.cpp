#include "TutorialState.h"



TutorialState::TutorialState(GameManager* g) : PlayState(g, 9, true, false)
{

}


TutorialState::~TutorialState()
{
}

void TutorialState::update(Uint32 time)
{
}

bool TutorialState::handleEvent(Uint32 time, SDL_Event e)
{
	return false;
}
