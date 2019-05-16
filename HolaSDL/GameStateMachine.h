#pragma once
#include <stack>
#include "GameState.h"
#include "checkML.h"

//A simple class that manages all the game's states

using namespace std;

class GameStateMachine
{
public:
	stack<GameState*> stack;

	GameStateMachine();
	~GameStateMachine();

	GameState* currentState();
	void changeState(GameState* state);
	void pushState(GameState* state);
	void popState();
};

