#include "QTEManager.h"
#include "SDLGame.h"


QTEManager::QTEManager(SDLGame* l)
{
	level = l;
	timer = Timer::Instance();
	timer->Reset();
}


QTEManager::~QTEManager()
{
}

void QTEManager::handleInput(Uint32 time, const SDL_Event& event) {
	if (flecha != nullptr)
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == flecha->getKey()/* && keyup*/)
		{
			//keyup = false;
			cout << "ejej";
			delete(flecha);
			flecha = nullptr;
			timer->Reset();
		}
		//if (event.type == SDL_KEYUP) keyup = true;
	}

}

void QTEManager::update(Uint32 time) {
	timer->Update();
	if (timer->DeltaTime() > 0.5f && flecha == nullptr)
	{
		if (rand()%1000 + 1 > 20 && rand() % 1000 + 1 < 21)
			flecha = new Flechas(SDLK_UP, level, 50, 50, Vector2D(400,200), Vector2D(0,0));
	}

}

void QTEManager::render(Uint32 time) {
	if (flecha != nullptr) flecha->render(time);
}
