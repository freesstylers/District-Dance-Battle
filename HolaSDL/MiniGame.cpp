#include "MiniGame.h"
#include "GameManager.h"


MiniGame::MiniGame(GameManager* g)
{
	manager = g;


	int aux;
	Flechas* flecha;

	for (int i = 0; i < 15; i++) {
		aux = rand() % 6;
		switch (aux) {
		case 0:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_A, manager, 50, 50, Vector2D(0, 0), Vector2D(2, 2));
			break;
		case 1:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_B, manager, 50, 50, Vector2D(g->getWindowWidth(), g->getWindowHeight()), Vector2D(-2, -2));
			break;
		case 2:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_X, manager, 50, 50, Vector2D(0, g->getWindowHeight()), Vector2D(2, -2));
			break;
		case 3:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_Y, manager, 50, 50, Vector2D(g->getWindowWidth(), 0), Vector2D(-2, 2));
			break;
		case 4:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_DPAD_DOWN, manager, 50, 50, Vector2D(g->getWindowWidth() / 2, 0), Vector2D(-1, 2));
			break;
		case 5:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_DPAD_UP, manager, 50, 50, Vector2D(0, g->getWindowHeight() / 2), Vector2D(2, -1));
			break;
		}
		flechas.push_back(flecha);
	}

}



MiniGame::~MiniGame()
{
}

