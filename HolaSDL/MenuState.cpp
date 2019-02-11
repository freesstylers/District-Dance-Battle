#include "MenuState.h"
//#include "Game.h"

MenuState::MenuState(Game* g) :GameState(g)
{
	game = g;

}

MenuState::~MenuState()
{
}

void MenuState::play(Game* game) {
	cout << "jugando" << endl;
	//game->getMachine()->pushState(new PlayState(game, 0));
}

void MenuState::load(Game * game)
{
	cout << "cargando" << endl;
	//game->getMachine()->pushState(new PlayState(game, 1));
}

void MenuState::exit(Game * game)
{
	cout << "saliendo" << endl;
	//game->exit();
}