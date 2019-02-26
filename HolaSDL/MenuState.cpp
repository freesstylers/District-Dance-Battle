#include "MenuState.h"
//#include "Game.h"

MenuState::MenuState(GameManager* g) :GameState(g)
{
	gameManager = g;
	stage.push_back(new Button(gameManager, 100, 100, Vector2D(0, 0), play));

}

MenuState::~MenuState()
{
}

void MenuState::play(GameManager* game) {
	cout << "jugando" << endl;
	//game->getMachine()->pushState(new PlayState(game, 0));
}

void MenuState::load(GameManager* game)
{
	cout << "cargando" << endl;
	//game->getMachine()->pushState(new PlayState(game, 1));
}

void MenuState::exit(GameManager* game)
{
	cout << "saliendo" << endl;
	//game->exit();
}

///////////////////////////////////////////////////////////////////////

/*

//Nueva partida

//Cargar partida

//Ajustes

//Salir

// ¿Extras?

*/