#include "GameManager.h"



GameManager::GameManager(): SDLGame("District Dance Battle", _WINDOW_WIDTH_, _WINDOW_HEIGHT_)
{
	machine = new GameStateMachine();
	exit_ = false;

	ifstream file("resources/data/options.ddb");

	if (file.is_open()) {
		string s;

		file >> s >> musicVolume_;

		file >> s >> soundVolume_;

		file >> s >> isXbox;
	}

	file.close();
}


GameManager::~GameManager()
{
	delete machine;
	machine = nullptr;
}

void GameManager::start() {
	//machine->pushState(new CreadorNiveles(this)); //Creador de niveles, descomentar esta parte y comentar la linea de abajo para crear niveles mas facil
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
	}
}

//Calculate delta time (time lapse every loop)
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
