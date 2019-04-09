#include "MapState.h"
#include "GameManager.h"


MapState::MapState(GameManager* g) :GameState(g)
{
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	createMainButtons();
	fondo__ = EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::Map);
	stage.push_back(new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::Map));
	activeLevels[0] = true;
	activeLevels[1] = true;
}

MapState::~MapState()
{
}

bool MapState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.type == SDL_CONTROLLERBUTTONDOWN || e.type == SDL_KEYDOWN) {
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
	buttons[0].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 - 50 , manager->getWindowHeight() / 2 - 30), 64, 64, Resources::MetroOn);
	buttons[1].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 + 25 , manager->getWindowHeight() / 2 + 100), 64, 64, Resources::MetroOn);
	buttons[2].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 + 75 , manager->getWindowHeight() / 2 - 85), 64, 64, Resources::MetroOn);
	buttons[3].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 - 180, manager->getWindowHeight() / 2 - 125), 64, 64, Resources::MetroOn);
	buttons[4].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 - 150, manager->getWindowHeight() / 2 - 75), 64, 64, Resources::MetroOn);
	buttons[0].second = PanelMap(manager, buttons[0].first.getPosition() - Vector2D(200, -20), Resources::CabezaVaporWave, 1, "D35P4C1T0", 1);
	buttons[1].second = PanelMap(manager, buttons[1].first.getPosition() - Vector2D(-30, 110), Resources::EminemciaHead, 3, "Eminemcia", 2);
	buttons[2].second = PanelMap(manager, buttons[2].first.getPosition(), Resources::CabezaVaporWave, 1, "D35P4C1T0", 1);
	buttons[3].second = PanelMap(manager, buttons[3].first.getPosition(), Resources::EminemciaHead, 3, "Eminemcia", 2);
	buttons[4].second = PanelMap(manager, buttons[4].first.getPosition(), Resources::CabezaVaporWave, 1, "D35P4C1T0", 1);

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
