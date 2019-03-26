#include "MiniGame.h"
#include "GameManager.h"
#include "PlayState.h"
#include "LevelInputManager.h"


MiniGame::MiniGame(GameManager* g, PlayState* p)
{
}


void MiniGame::update(Uint32 time) {
	
}

void MiniGame::handleInput(Uint32 time, SDL_Event e)
{
}

void MiniGame::createList()
{
}

void MiniGame::deleteList()
{
}

void MiniGame::updateResolution(double wScale, double hScale)
{
	for (Note* n : screenButtons_) {
		n->updateResolution(wScale, hScale);
	}

	for (Note* n : levelButtons_) {
		n->updateResolution(wScale, hScale);
	}

	fback->updateResolution(wScale, hScale);
}


void MiniGame::render(Uint32 time) {
	
}


