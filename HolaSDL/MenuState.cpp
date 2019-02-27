#include "MenuState.h"
//#include "Game.h"


MenuState::MenuState(GameManager* g) :GameState(g)
{
	gameManager = g;
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	int width = 100;
	int height = 100;
	stage.push_back(new Button(gameManager, width, height, Vector2D((2* gameManager->getWindowWidth() - gameManager->getWindowWidth())/6- height/2, gameManager->getWindowHeight()/2 - height/2), play));
	stage.push_back(new Button(gameManager, width, height, Vector2D((4* gameManager->getWindowWidth() - gameManager->getWindowWidth())/6- height/2, gameManager->getWindowHeight()/2 - height / 2), play));
	stage.push_back(new Button(gameManager, width, height, Vector2D((6* gameManager->getWindowWidth() - gameManager->getWindowWidth()) /6- height/2, gameManager->getWindowHeight()/2 - height / 2), creaBotones));
	primerBoton = stage.begin();
	botonActual = primerBoton;
	(*botonActual)->scale(2);
}

MenuState::~MenuState()
{
}

bool MenuState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.type == SDL_CONTROLLERBUTTONDOWN) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) {
			nextButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) {
			backButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A)) {
			static_cast<Button*>((*botonActual))->callCallback();
		}
	}
	return GameState::handleEvent(time, e);
}

void MenuState::creaBotonesPrincipales()
{

}

void MenuState::nextButton()
{
	(*botonActual)->scale(0.5);
	botonActual++;
	if (botonActual == stage.end()) {
		botonActual = primerBoton;
	}
	(*botonActual)->scale(2);
}

void MenuState::backButton()
{
	(*botonActual)->scale(0.5);
	if (botonActual == primerBoton) {
		while ((*botonActual) != stage.back()) {
			botonActual++;
		}
	}
	else {
		botonActual--;
	}
	(*botonActual)->scale(2);
}

void MenuState::play(GameManager* game) {
	cout << "jugando" << endl;
	game->getMachine()->pushState(new PlayState(game));
}

void MenuState::creaBotones(GameManager * gameManager)
{
	int width = 50;
	int height = 50;
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((4 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getWindowHeight() / 3 - height / 2), play));
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((5 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getWindowHeight() / 3 - height / 2), play));
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((6 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getWindowHeight() / 3 - height / 2), play));
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