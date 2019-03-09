#include "MenuState.h"


MenuState::MenuState(GameManager* g) :GameState(g)
{
	gameManager = g;
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	/*int width = 100;
	int height = 100;
	stage.push_back(new Button(gameManager, width, height, Vector2D((2 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getWindowHeight() / 2 - height / 2), playLevel));
	primerBoton = stage.begin();
	stage.push_back(new Button(gameManager, width, height, Vector2D((4 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getWindowHeight() / 2 - height / 2), playPrueba));
	stage.push_back(new Button(gameManager, width, height, Vector2D((6 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getWindowHeight() / 2 - height / 2), creaBotones));
	botonActual = primerBoton;
	(*botonActual)->scale(2);*/
	creaBotonesPrincipales();
}

MenuState::~MenuState()
{
}

bool MenuState::handleEvent(Uint32 time, SDL_Event e)
{
	//if (e.type == SDL_CONTROLLERBUTTONDOWN) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RIGHT) {
			nextButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || e.key.keysym.sym == SDLK_LEFT) {
			backButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A)|| e.key.keysym.sym == SDLK_RETURN) {
			static_cast<Button*>((*botonActual))->callCallback();
		}else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)|| e.key.keysym.sym == SDLK_DELETE) {
			creaBotonesPrincipales();
		}
	//}
	return GameState::handleEvent(time, e);
}

void MenuState::destruirBotones()
{
	if (!stage.empty()) {
		botonActual = primerBoton;
		auto it = botonActual;
		while (botonActual != stage.end()) {
			it++;
			stage.erase(botonActual);
			botonActual = it;
		}
	}
}

void MenuState::creaBotonesPrincipales()
{
	destruirBotones();
	int width = 100;
	int height = 100;
	stage.push_back(new Button(gameManager, width, height, Vector2D((2 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getWindowHeight() / 2 - height / 2), playLevel, 0));
	primerBoton = stage.begin();
	stage.push_back(new Button(gameManager, width, height, Vector2D((4 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getWindowHeight() / 2 - height / 2), playPrueba, 2));
	stage.push_back(new Button(gameManager, width, height, Vector2D((6 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getWindowHeight() / 2 - height / 2), playPrueba, 1));
	botonActual = primerBoton;
	(*botonActual)->scale(2);
}

void MenuState::nextButton()
{
	(*botonActual)->scale(0.5);
	if ((*botonActual) != stage.back()) {
		botonActual++;
	}
	(*botonActual)->scale(2);
}

void MenuState::backButton()
{
	(*botonActual)->scale(0.5);
	if (botonActual != primerBoton) {
		botonActual--;
	}
	(*botonActual)->scale(2);
}

void MenuState::playLevel(GameManager* game) {
	cout << "jugando" << endl;
	game->getMachine()->pushState(new PlayState(game, "level"));
}

void MenuState::playPrueba(GameManager* game) {
	cout << "jugando" << endl;
	game->getMachine()->pushState(new PlayState(game, "prueba"));
}

void MenuState::creaBotones(GameManager * gameManager)
{
	static_cast<MenuState*>(gameManager->getMachine()->currentState())->destruirBotones();
	int width = 50;
	int height = 50;
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((4 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getWindowHeight() / 3 - height / 2), playLevel, 0));
	static_cast<MenuState*>(gameManager->getMachine()->currentState())->primerBoton = gameManager->getMachine()->currentState()->stage.begin();
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((5 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getWindowHeight() / 3 - height / 2), playPrueba, 2));
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((6 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getWindowHeight() / 3 - height / 2), playPrueba, 1));
	static_cast<MenuState*>(gameManager->getMachine()->currentState())->botonActual = static_cast<MenuState*>(gameManager->getMachine()->currentState())->primerBoton;
	(*static_cast<MenuState*>(gameManager->getMachine()->currentState())->botonActual)->scale(2);

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

//¿Extras?

*/