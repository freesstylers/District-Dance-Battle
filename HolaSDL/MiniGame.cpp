#include "MiniGame.h"
#include "GameManager.h"
#include "PlayState.h"


MiniGame::MiniGame(GameManager* g, PlayState* p)
{
	manager = g;
	playS = p;

	int aux;
	Flechas* flecha;

	for (int i = 0; i < 15; i++) {
		aux = rand() % 8;
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
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_A, manager, 50, 50, Vector2D(g->getWindowWidth() / aux, 0), Vector2D(-1, 2));
			break;
		case 5:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_B, manager, 50, 50, Vector2D(0, g->getWindowHeight() / aux), Vector2D(2, -1));
			break;
		case 6:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_X, manager, 50, 50, Vector2D(0, g->getWindowHeight() / aux), Vector2D(2, -1));
			break;
		case 7:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_Y, manager, 50, 50, Vector2D(0, g->getWindowHeight() / aux), Vector2D(2, -1));
			break;
		}
		botonesNivel_.push_back(flecha);
	}

}

void MiniGame::update(Uint32 time) {
	//if (fallado == false) {
	for (Flechas* o : botonesPantalla_)
	{
		o->update(time);
	}
	if (rand() % 1000 + 1 > 20 && rand() % 1000 + 1 < 5)
	{
		generaBotones();
		playS->timer->Reset();


	}
	//}
}
bool MiniGame::handleInput(Uint32 time, const SDL_Event& event) {

	if (!playS->botonesPantalla_.empty())
	{
		auto it = playS->botonesPantalla_.front();
		if (it != nullptr) {
			if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup2)
			{
				keyup = false;
				if (abs(it->getPosition().getY()) > 0 && abs(it->getPosition().getY()) < manager->getWindowHeight() && abs(it->getPosition().getX()) > 0 && abs(it->getPosition().getX()) < manager->getWindowWidth())
				{
					cout << "perfecto" << endl;
				}
				else {
					fallado = false;
				}
				
				delete(it);
				playS->botonesPantalla_.remove(it);
			}
			else if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup2)
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
					SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))
				{
					keyup2 = false;
					delete(it);
					playS->botonesPantalla_.remove(it);
					cout << "flecha incorrecta" << endl;
				}
			}
			if (event.type == SDL_CONTROLLERBUTTONUP) keyup2 = true;
		}
	}

	return true;
}

void MiniGame::render(Uint32 time) {
	for (Flechas* o : botonesPantalla_)
	{
		o->render(time);
	}
}

void MiniGame::generaBotones() {
	if (!botonesNivel_.empty()) {
		if (botonesNivel_.back() != nullptr) {
			botonesPantalla_.push_back(botonesNivel_.back());
		}
		botonesNivel_.pop_back();
	}
}

MiniGame::~MiniGame()
{
}

