#include "GameManager.h"



GameManager::GameManager(): SDLGame("District Dance Battle", _WINDOW_WIDTH_, _WINDOW_HEIGHT_)
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
	//supposed to push the first MapState, temporarily pushes a PlayState
	//machine->pushState(new MapState(this));
	//machine->pushState(new DialogState(this, "Dialog0", 0));
	//machine->pushState(new DialogState(this,1		,0));
	//machine->pushState(new DialogState(this,"Dialog0",0));
	//machine->pushState(new EndState(this,60,100,10,1));
	machine->pushState(new MainMenuState(this));
	run();
}

void GameManager::stop() {
	exit_ = true;
}

GameStateMachine * GameManager::getMachine()
{
	return machine;
}

void GameManager::run()
{
	while (!exit_) {
		double startTime = SDL_GetTicks();
		handleEvent(startTime);
		update(startTime);
		render(startTime);
		tick();
		/*double frameTime = SDL_GetTicks() - startTime;
		double frames = (1.0 / (double)MAXFPS)*1000.0;
		if (frameTime < frames) {
			SDL_Delay(frames - frameTime);
			deltaTime = frames/1000.0;
		}
		else {
			deltaTime = frameTime/ 1000.0;
		}*/
	}
}

void GameManager::tick()
{
	uint32_t tick_time = SDL_GetTicks();
	deltaTime = (tick_time - last_tick_time);
	last_tick_time = tick_time;
}

void GameManager::update(Uint32 time)
{
	machine->currentState()->update(time);
}

void GameManager::handleEvent(Uint32 time)
{
	SDL_Event event;
	bool handled = false;
	bool ent_mainmenu = true;
	while (SDL_PollEvent(&event) && !exit_ && ent_mainmenu) {
		if (event.type == SDL_QUIT)
			exit_ = true;
		machine->currentState()->handleEvent(time, event);
		if (mainmenu == true)
		{
			ent_mainmenu = false;
		}
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
