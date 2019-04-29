#pragma once
#include "GameState.h"
#include "EmptyObject.h"
#include "GameManager.h"

using namespace std;
class MainMenuState :
	public GameState
{
public:
	MainMenuState(GameManager* g);
	~MainMenuState();

	virtual void render(Uint32 time, bool beatHandler);

	pair<EmptyObject*, bool> buttons[2];

private:
	GameManager* gameManager;
};

