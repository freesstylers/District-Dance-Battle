#include "MiniGame.h"
#include "GameManager.h"
#include "PlayState.h"
#include "LevelInputManager.h"


MiniGame::MiniGame(GameManager* g, PlayState* p)
{
	manager = g;
	playS = p;
	fback = new Feedback(g, 150, 150, Vector2D(g->getWindowWidth() / 2 - 150 / 2, g->getWindowHeight() / 2 - 150 / 2));
	timer = new TimerNoSingleton();


	creaLista();
}

void MiniGame::creaLista()
{
	int newpos;
	int aux;
	fallado = false;
	nFlechas = 15;
	Flechas* flecha;
	for (int i = 0; i < 15; i++) {
		aux = rand() % 8;

		switch (aux) {
		case 0:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_A, manager, 75, 75, Vector2D(0, 0), Vector2D(200, 200));
			break;
		case 1:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_B, manager, 75, 75, Vector2D(0, 0), Vector2D(200, 200));
			break;
		case 2:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_X, manager, 75, 75, Vector2D(manager->getWindowWidth(), 0), Vector2D(-200, 200));
			break;
		case 3:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_Y, manager, 75, 75, Vector2D(manager->getWindowWidth(), 0), Vector2D(-200, 200));
			break;
		case 4:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_A, manager, 75, 75, Vector2D(0, manager->getWindowHeight()), Vector2D(200, -200));
			break;
		case 5:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_B, manager, 75, 75, Vector2D(0, manager->getWindowHeight()), Vector2D(200, -200));
			break;
		case 6:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_X, manager, 75, 75, Vector2D(manager->getWindowWidth(), manager->getWindowHeight()), Vector2D(-200, -200));
			break;
		case 7:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_Y, manager, 75, 75, Vector2D(manager->getWindowWidth(), manager->getWindowHeight()), Vector2D(-200, -200));
			break;
		}
		botonesNivel_.push_back(flecha);
	}
}
void MiniGame::update(Uint32 time) {
	if (!botonesPantalla_.empty()) {
		for (Flechas* o : botonesPantalla_)
		{
			o->update(time);
		}
	}

	timer->Update();
	if (timer->DeltaTime() > (playS->bh->getBeatTime() / 1000.0) && nFlechas > 0)
	{
		//playS->msDiff += timer->DeltaTime() - (playS->bh->getBeatTime() / 1000.0);
		generaBotones();
		
		timer->Reset();

		nFlechas--;
	}
	else if (botonesNivel_.empty()&& botonesPantalla_.empty() && nFlechas <= 0) {
		fallado = true;
	}
	
}


void MiniGame::render(Uint32 time) {
	for (Flechas* o : botonesPantalla_)
	{
		o->render(time);
	}
	fback->render(time);
}

void MiniGame::generaBotones() {
	if (!botonesNivel_.empty()) {
		if (botonesNivel_.back() != nullptr) {
			botonesPantalla_.push_back(botonesNivel_.back());
		}
		botonesNivel_.pop_back();
	}
}


