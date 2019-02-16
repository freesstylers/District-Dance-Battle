#include "DemoGame.h"

//ESTE DEMOGAME ES COMO LA ESCENA DEL JUEGO
//LA USAMOS PARA PROBAR LAS BATALLAS, NO ES DEFINITIVA

#include <cstdlib>
#include <fstream>

using namespace std;

DemoGame::DemoGame() :
		SDLGame("Demo", _WINDOW_WIDTH_, _WINDOW_HEIGHT_) {
	initGame();
	exit_ = false;
}

DemoGame::~DemoGame() {
	closeGame();
}

void DemoGame::initGame() {

	/*	Inicializacion de todo lo necesario
	*	que vaya a aparecer en la escena
	*/
	timer = Timer::Instance();
	punto = new Point(this, 80, 80, Vector2D(100, 330));
	bh = new BeatHandeler(112);

	velFlechas = asignaVel(bh->getBeatTime());
	ifstream file("resources/levels/prueba.txt");
	int aux;
	Flechas* flecha;
	for (int i = 0; i < 25; i++) {
		file >> aux;
		switch (aux) {
		case 0:
			flecha = nullptr;
			break;
		case 1:
			flecha = new Flechas(SDLK_LEFT, this, 50, 50, posFlechaInicial ,velFlechas);
			break;
		case 2:
			flecha = new Flechas(SDLK_RIGHT, this, 50, 50, posFlechaInicial, velFlechas);
			break;
		case 3:
			flecha = new Flechas(SDLK_UP, this, 50, 50, posFlechaInicial, velFlechas);
			break;
		case 4:
			flecha = new Flechas(SDLK_DOWN, this, 50, 50, posFlechaInicial, velFlechas);
			break;
		}
		flechasNivel_.push_front(flecha);
	}
	file.close();

	
	actors_.push_back(punto);
}

void DemoGame::closeGame() {
	for (GameObject* o : actors_) {
		delete o;
	}
	for (Flechas* o : flechasPantalla_)
	{
		delete o;
	}
}

void DemoGame::start() {
	exit_ = false;
	getServiceLocator()->getAudios()->playChannel(Resources::Pruebas, -1);
	getServiceLocator()->getAudios()->setChannelVolume(70);
	while (!exit_) {
		Uint32 startTime = SDL_GetTicks();
		handleInput(startTime);
		update(startTime);
		render(startTime);

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void DemoGame::stop() {
	exit_ = true;
}

void DemoGame::handleInput(Uint32 time) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
			exit_ = true;
			break;
		}
		// Pressing f to toggle fullscreen.
		else if (event.key.keysym.sym == SDLK_f)
		{
			int flags = SDL_GetWindowFlags(window_);
			if (flags & SDL_WINDOW_FULLSCREEN) {
				SDL_SetWindowFullscreen(window_, 0);
			}
			else {
				SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN);
			}
		}
		else
		{
			if (!flechasPantalla_.empty())
			{
				auto it = flechasPantalla_.front();
				if (it != nullptr)
				{
					if (event.type == SDL_KEYUP && event.key.keysym.sym == it->getKey())
					{
						if (abs(it->getPosition().getX() - punto->getPosition().getX()) <= 25)
						{
							cout << "perfecto" << endl;
						}
						else if (abs(it->getPosition().getX() - punto->getPosition().getX()) <= 50)
						{
							cout << "bien" << endl;
						}
						else if (abs(it->getPosition().getX() - punto->getPosition().getX()) <= 100)
						{
							cout << "regular" << endl;
						}
						else
						{
							cout << "mala punteria" << endl;
						}
						delete(it);
						flechasPantalla_.remove(it);
					}
					else if (event.type == SDL_KEYUP)
					{
						delete(it);
						flechasPantalla_.remove(it);
						cout << "flecha incorrecta" << endl;
					}
				}
			}
		}

		for (GameObject* o : actors_) {
			o->handleInput(time, event);
		}
	}
}

void DemoGame::update(Uint32 time) {
	for (GameObject* o : actors_) {
		o->update(time);
	}
	for (Flechas* o : flechasPantalla_)
	{
		o->update(time);
	}
	if (!flechasPantalla_.empty() && flechasPantalla_.front()->getPosition().getX() < 50)
	{

		flechasPantalla_.pop_front();
		cout << "fuera" << endl;
		
	}
	timer->Update();
	if (timer->DeltaTime() < (bh->getBeatTime()/1000) + 0.010 && timer->DeltaTime() > (bh->getBeatTime() / 1000) - 0.010)
	{
		generate();
		timer->Reset();
	}
}

void DemoGame::render(Uint32 time) {
	SDL_SetRenderDrawColor(getRenderer(), COLOR(0x00AAAAFF));
	SDL_RenderClear(getRenderer());

	for (GameObject* o : actors_) {
		o->render(time);
	}

	for (Flechas* o : flechasPantalla_)
	{
		o->render(time);
	}

	SDL_RenderPresent(getRenderer());
}

void DemoGame::generate()
{
	if (!flechasNivel_.empty()) {
		if (flechasNivel_.back() != nullptr) {
			flechasPantalla_.push_back(flechasNivel_.back());
			flechasNivel_.pop_back();
		} else flechasNivel_.pop_back();
	} 
}
Vector2D DemoGame::asignaVel(double time) {
	double distance = posFlechaInicial.getX() - (punto->getPosition().getX() + punto->getWidth()/2);
	double velocity = distance / bh->getBeatTime();
	return Vector2D(-velocity*4, 0);
}
