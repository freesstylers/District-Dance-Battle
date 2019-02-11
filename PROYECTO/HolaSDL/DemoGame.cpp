#include "DemoGame.h"

//ESTE DEMOGAME ES COMO LA ESCENA DEL JUEGO
//LA USAMOS PARA PROBAR LAS BATALLAS, NO ES DEFINITIVA

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
	SDL_Keycode  key = SDLK_LEFT;
	Flechas* flecha1 = new Flechas(key, this, 50, 50, Vector2D(700, 350), Vector2D(-5, 0));
	flechas_.push_back(flecha1);
	timer = Timer::Instance();
	punto = new Point(this, 80, 80, Vector2D(100, 330));
	bh = new BeatHandeler(112);
	bh->getBeatTime();

	actors_.push_back(punto);
}

void DemoGame::closeGame() {
	for (GameObject* o : actors_) {
		delete o;
	}
	for (Flechas* o : flechas_)
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
			if (!flechas_.empty())
			{
				auto it = flechas_.front();
				if (it != nullptr)
				{
					if (event.type == SDL_KEYUP && event.key.keysym.sym == it->getKey())
					{
						if (abs(it->getPosition().getX() - punto->getPosition().getX()) <= 100)
						{
							cout << "bien";
						}
						else
						{
							cout << "mal";
						}
						delete(it);
						flechas_.remove(it);
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
	for (Flechas* o : flechas_)
	{
		o->update(time);
	}
	if (!flechas_.empty() && flechas_.front()->getPosition().getX() < 50)
	{

		flechas_.pop_front();
		cout << "mal";
		
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

	for (Flechas* o : flechas_)
	{
		o->render(time);
	}

	SDL_RenderPresent(getRenderer());
}

void DemoGame::generate()
{
	SDL_Keycode  key = SDLK_LEFT;
	Flechas* flecha1 = new Flechas(key, this, 50, 50, Vector2D(700, 350), Vector2D(-5, 0));
	flechas_.push_back(flecha1);
}

