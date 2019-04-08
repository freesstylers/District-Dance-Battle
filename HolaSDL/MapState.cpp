#include "MapState.h"
#include "GameManager.h"


MapState::MapState(GameManager* g) :GameState(g)
{
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	createMainButtons();
	activeLevels[0] = true;
}

MapState::~MapState()
{
}

bool MapState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.type == SDL_CONTROLLERBUTTONDOWN) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RIGHT) {
			buttons[index].second.reset();
			nextButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || e.key.keysym.sym == SDLK_LEFT) {
			buttons[index].second.reset();
			backButton();
		}
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || e.key.keysym.sym == SDLK_UP) {
			buttons[index].second.nextSwitch();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || e.key.keysym.sym == SDLK_DOWN) {
			buttons[index].second.prevSwitch();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN) {
			buttons[index].second.selectButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || e.key.keysym.sym == SDLK_DELETE) {

		}
	}
	return GameState::handleEvent(time, e);
}

void MapState::render(Uint32 time, bool beatSync)
{
	GameState::render(time);
	for (auto o : buttons) {
		o.first.render(time, false);
	}
	buttons[index].second.render(time, false);
}

void MapState::createMainButtons()
{
	int ang = 360 / 5;
	int angIni = 270;
	int angulo;
	int r = 150;
	for (int i = 0; i < 5; i++) {
		angulo = angIni + ang * i;
		buttons[i].first = EmptyObject(manager, Vector2D((manager->getWindowWidth() / 2 + r * cos(((angulo*M_PI) / 180))) - 25, (manager->getWindowHeight() / 2 + r * sin(((angulo*M_PI) / 180))) - 25), 50, 50, Resources::YButton);
		buttons[i].second = PanelMap(manager, buttons[i].first.getPosition(), Resources::CabezaVaporWave, 1, "D35P4C1T0", 2);
	}

	buttons[0].first.scale(2);
}

void MapState::nextButton()
{
	buttons[index].first.scale(0.5);

	do
	{
		if (index < max) {
			index++;
		}
		else {
			index = min;
		}
	} while (!activeLevels[index]);

	buttons[index].first.scale(2);
}

void MapState::backButton()
{
	buttons[index].first.scale(0.5);

	do
	{
		if (index > min) {
			index--;
		}
		else {
			index = max;
		}
	} while (!activeLevels[index]);

	buttons[index].first.scale(2);
}

void MapState::play(int lvl_) {
	cout << "jugando" << endl;
	//gameManager->getMachine()->pushState(new PlayState(game, ));
	//gameManager->getMachine()->pushState(new DialogState(gameManager, lvl_, 0));
}

void MapState::load(GameManager* game)
{

}

void MapState::exit(GameManager* game)
{

}
