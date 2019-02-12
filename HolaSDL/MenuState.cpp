#include "MenuState.h"
//#include "Game.h"

MenuState::MenuState(GameManager* g) :GameState(g)
{
	gameManager = g;

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