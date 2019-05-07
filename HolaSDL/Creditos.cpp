#include "Creditos.h"
#include "PlayState.h"
#include "GameManager.h"



Creditos::Creditos(GameManager* game) :GameState(game)
{
	controller = SDL_GameControllerOpen(0);
	init();
	manager = game;

}

void Creditos::init() {

	bg = new EmptyObject(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::MenuCanciones);
}
Creditos::~Creditos()
{
	delete bg;
	bg = nullptr;
}

bool Creditos::handleEvent(Uint32 time, SDL_Event event)
{
	GameState::handleEvent(time, event);

	if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYUP) {

		}
	if ( event.key.keysym.sym == SDLK_RETURN || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)) {
		manager->getMachine()->changeState(new MainMenuState(manager));
	}

	return false;
}

void Creditos::render(Uint32 time, bool beatSync)
{
	bg->render(time);




}
