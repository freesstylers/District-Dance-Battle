#pragma once
#include "GameState.h"

class MenuState : public GameState //Clase general para menus, he dejado los métodos estáticos para hacer los callbacks
{
public:
	MenuState(GameManager* g);
	~MenuState();

	static void play(GameManager* gameManager);
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

private:
	GameManager* gameManager;
};