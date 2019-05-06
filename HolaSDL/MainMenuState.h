#pragma once
#include "GameState.h"
#include "EmptyObject.h"
#include "GameManager.h"
#include "checkML.h"

using namespace std;
class MainMenuState :
	public GameState
{
public:
	MainMenuState(GameManager* g);
	~MainMenuState();
	static void newGame(GameManager*gameManager);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatHandler);

	pair<EmptyObject*, bool> buttons[3];

private:
	GameManager* gameManager;
	void nextButton();
	void backButton();
	int index = 0;
	int max=2;
	int min = 0;
	SDL_GameController* controller = NULL;
};

