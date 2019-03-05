#include "MiniGame.h"
#include "GameManager.h"
#include "PlayState.h"
#include "LevelInputManager.h"


MiniGame::MiniGame(GameManager* g, PlayState* p)
{
	manager = g;
	playS = p;

	int newpos;
	int aux;
	Flechas* flecha;

	for (int i = 0; i < 15; i++) {
		aux = rand() % 8;

		/*
		if (aux + 1 < g->getWindowHeight / 2)
		{
			//+y
		}
		else
		{
			//-y
		}
		if (aux + 1 < g->getWindowWidth / 2)
		{
			//+x
		}
		else
		{
			//-x
		}*/
		switch (aux) {
		case 0:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_A, manager, 75, 75, Vector2D(g->getWindowWidth() / (aux + 1), 0), Vector2D(7, 7));
			break;
		case 1:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_B, manager, 75, 75, Vector2D(g->getWindowWidth() /( aux + 1), 0), Vector2D(-7, -7));
			break;
		case 2:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_X, manager, 75, 75, Vector2D(g->getWindowWidth() /( aux + 1), 0), Vector2D(7, -7));
			break;
		case 3:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_Y, manager, 75, 75, Vector2D(g->getWindowWidth()/(aux + 1), 0),Vector2D(-7, 7));
			break;
		case 4:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_A, manager, 75, 75, Vector2D(0, g->getWindowHeight() /( aux + 1)), Vector2D(g->getWindowWidth() /aux * 7, aux));
			break;
		case 5:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_B, manager, 75, 75, Vector2D(0, g->getWindowHeight() /( aux + 1)), Vector2D(g->getWindowWidth() / aux * 7, - aux));
			break;
		case 6:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_X, manager, 75, 75, Vector2D(0, g->getWindowHeight() / (aux + 1)), Vector2D(g->getWindowWidth() / aux * 7, -aux));
			break;
		case 7:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_Y, manager, 75, 75, Vector2D(0, g->getWindowHeight() /( aux + 1)), Vector2D(g->getWindowWidth() / aux * 7, -aux));
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

	if (rand() % 1000 + 1 > 1 && rand() % 1000 + 1 < 2)
	{
		generaBotones();
		playS->timer->Reset();


	}
	//}
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

