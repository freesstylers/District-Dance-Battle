#pragma once
#include "MiniGame.h"

class PlayState;
class GameManager;

class MinigameHipHop : public MiniGame
{
public:
	MinigameHipHop(GameManager* g, PlayState* p);;
	~MinigameHipHop();
};

