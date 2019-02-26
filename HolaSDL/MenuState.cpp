#include "MenuState.h"
//#include "Game.h"


MenuState::MenuState(GameManager* g) :GameState(g)
{
	gameManager = g;
	int weight = gameManager->getWindowWidth();
	int height = gameManager->getWindowHeight();
	stage.push_back(new Button(gameManager, 100, 100, Vector2D((2*weight-weight)/6-50, height/2-50), play));
	stage.push_back(new Button(gameManager, 100, 100, Vector2D((4* weight - weight )/6-50,height/2-50), play));
	stage.push_back(new Button(gameManager, 100, 100, Vector2D((6* weight - weight) /6-50, height / 2-50), play));

}

MenuState::~MenuState()
{
}

bool MenuState::handleEvent(Uint32 time, SDL_Event e)
{

	return false;
}

void MenuState::play(GameManager* game) {
	cout << "jugando" << endl;
	game->getMachine()->pushState(new PlayState(game));
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