#include "Credits.h"
#include "PlayState.h"
#include "GameManager.h"



Credits::Credits(GameManager* game) :GameState(game)
{
	controller = SDL_GameControllerOpen(0);
	init();
	manager = game;

}

void Credits::init() {

	bg = new EmptyObject(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::Credits);
}

Credits::~Credits()
{
	delete bg;
	bg = nullptr;
}

bool Credits::handleEvent(Uint32 time, SDL_Event event)
{
	GameState::handleEvent(time, event);

	if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYUP) {

		}
	if ( event.key.keysym.sym == SDLK_RETURN || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)) {
		manager->mainmenu = true;
		manager->getMachine()->changeState(new MainMenuState(manager));
	}

	return false;
}

void Credits::render(Uint32 time, bool beatSync)
{
	bg->render(time);




}
