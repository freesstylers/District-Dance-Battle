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
	static void exit_(GameManager* gameManager);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	std::list<GameObject*>::iterator firstButton;
	std::list<GameObject*>::iterator selectedButton;
private:
	//void createButtons();
	GameManager* gameManager;
	SDL_GameController* controller = NULL;
	void nextButton();
	void backButton();
};

