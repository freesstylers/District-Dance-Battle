#pragma once
#include "GameState.h"
#include "Button.h"

class MenuState : public GameState //Clase general para menus, he dejado los métodos estáticos para hacer los callbacks
{
public:
	MenuState(GameManager* g);
	~MenuState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);

	std::list<GameObject*>::iterator primerBoton;
	std::list<GameObject*>::iterator botonActual;

private:
	static void play(GameManager* gameManager);
	static void creaBotones(GameManager* gameManager);
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;
	
	GameManager* gameManager;
	
	void creaBotonesPrincipales();
	void destruirBotones();
	void nextButton();
	void backButton();
};