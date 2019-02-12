#include "GameManager.h"



GameManager::GameManager(SDLGame* g)
{
	game = g;
	exit_ = false;
}


GameManager::~GameManager()
{
}

void GameManager::exit()
{
	exit_ = true;
}

bool GameManager::checkExit()
{
	return exit_;
}

SDLGame* GameManager::getGame()
{
	return game;
}
