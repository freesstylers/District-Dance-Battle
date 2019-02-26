#pragma once
#include "GameState.h"
#include "Button.h"

class MenuState : public GameState //Clase general para menus, he dejado los m�todos est�ticos para hacer los callbacks
{
public:
	MenuState(GameManager* g);
	~MenuState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);

private:
	static void play(GameManager* gameManager);
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);
	GameManager* gameManager;
};