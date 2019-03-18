#pragma once
#include "GameState.h"
#include "Button.h"

class MenuState : public GameState //main class for menus
{
public:
	MenuState(GameManager* g);
	~MenuState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);

	std::list<GameObject*>::iterator firstButton;
	std::list<GameObject*>::iterator selectedButton;

private:
	static void play(GameManager* gameManager);
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;
	
	GameManager* gameManager;
	
	void createMainButtons();
	void deleteButtons();
	void nextButton();
	void backButton();
};