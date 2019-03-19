#pragma once
#include "GameState.h"
#include "Button.h"
#include "EmptyObject.h"

class MenuState : public GameState //main class for menus
{
public:

	MenuState(GameManager* g);
	~MenuState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync);

private:

	EmptyObject buttons[15];

	int index = 0;
	int min = 0;
	int max = 4;

	static void play(GameManager* gameManager);
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;
	
	GameManager* gameManager;

	void createMainButtons();
	void nextButton();
	void backButton();
	void reset();
	void deactivateAll();
	void activate(int first, int last);
	void buttonUse();

};