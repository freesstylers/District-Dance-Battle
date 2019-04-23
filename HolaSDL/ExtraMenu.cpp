#include "ExtraMenu.h"
#include "PlayState.h"
#include "GameManager.h"



ExtraMenu::ExtraMenu(GameManager* game):GameState(game)
{
	controller = SDL_GameControllerOpen(0);
	init();
	manager = game;

}

void ExtraMenu::init() {

	bg = new EmptyObject(manager, Vector2D( 0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::MenuCanciones);
	hand = new EmptyObject(manager, Vector2D(1300, 85), 192, 192, Resources::MasterHand);
	posHand = 0;
}
ExtraMenu::~ExtraMenu()
{
}

void ExtraMenu::selectionUp() {
	if (posHand == 4) {
		posHand = 0;
		hand->setPosition(Vector2D(hand->getPosition().getX(), 85));
	}
	else {
		posHand++;
		hand->setPosition(Vector2D(hand->getPosition().getX(), hand->getPosition().getY()+ 185));
	}
}

void ExtraMenu::selectionDown() {
	if (posHand == 0) {
		posHand = 4;
		hand->setPosition(Vector2D(hand->getPosition().getX(), 825));
	}
	else {
		posHand--;
		hand->setPosition(Vector2D(hand->getPosition().getX(), hand->getPosition().getY() - 185));
	}
}

bool ExtraMenu::handleEvent(Uint32 time,  SDL_Event event)
{
	if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYUP) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || event.key.keysym.sym == SDLK_UP) {
			
			selectionDown();
			cout << "Up" << endl;

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || event.key.keysym.sym == SDLK_DOWN) {

			selectionUp();
			cout << "Down" << endl;

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || event.key.keysym.sym == SDLK_RETURN) {
			
			switch (posHand)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				break;
			}

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || event.key.keysym.sym == SDLK_DELETE) {
				
			manager->getMachine()->pushState(new MapState(manager));
				
		}
	}
	cout << "lul" << endl;

	return false;
}

void ExtraMenu::render(Uint32 time, bool beatSync)
{
		bg->render(time);
		hand->render(time);

	
}
