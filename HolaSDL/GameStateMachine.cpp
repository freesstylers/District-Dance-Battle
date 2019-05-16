#include "GameStateMachine.h"

GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
	while (!stack.empty())
	{
		delete stack.top();
		stack.pop();
	}
}

GameState* GameStateMachine::currentState()
{
	return stack.top();
}

void GameStateMachine::pushState(GameState* state)
{
	stack.push(state);
}

void GameStateMachine::popState()
{
	delete stack.top();
	stack.pop();
}

void GameStateMachine::changeState(GameState* state)
{
	popState();
	pushState(state);
}

void GameStateMachine::cleanStack() {
	for (int i = 0; i < stack.size(); i++)
		popState();
}