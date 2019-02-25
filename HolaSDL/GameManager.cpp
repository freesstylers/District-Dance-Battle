#include "GameManager.h"



GameManager::GameManager(): SDLGame("FreeStylers", _WINDOW_WIDTH_, _WINDOW_HEIGHT_)
{
	machine = new GameStateMachine();
	exit_ = false;
}


GameManager::~GameManager()
{
	delete machine;
	machine = nullptr;
}

void GameManager::start() {
	//entra el primer estado, aunque por ahora sera el PlayState
	machine->pushState(new PlayState(this));
	run();
}

void GameManager::stop() {
	exit_ = true;
}

void GameManager::run()
{
	while (!exit_) {
		Uint32 startTime = SDL_GetTicks();
		handleEvent(startTime);
		update(startTime);
		render(startTime);

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void GameManager::update(Uint32 time)
{
	machine->currentState()->update(time);
}

void GameManager::handleEvent(Uint32 time)
{
	SDL_Event event;
	bool handled = false;
	while (SDL_PollEvent(&event) && !exit_ && !handled) {
		if (event.type == SDL_QUIT)
			exit_ = true;
		handled = machine->currentState()->handleEvent(time, event);
	}
}


void GameManager::render(Uint32 time)
{
	SDL_RenderClear(getRenderer());

	machine->currentState()->render(time);

	SDL_RenderPresent(getRenderer());
}

bool GameManager::checkExit()
{
	return exit_;
}