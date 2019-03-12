#pragma once
#include "GameState.h"
#include "Button.h"
#include "Character.h"

class EndState :
	public GameState
{
public:
	EndState(GameManager* g, int actualScore, int maxScore, int percentage);
	virtual ~EndState();
	static void backToMenu(GameManager* gameManager);
};

