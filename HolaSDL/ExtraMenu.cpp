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

	bg = new EmptyObject(manager, Vector2D( 0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::MenuCanciones);
	hand = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth()-400, manager->getDefaultWindowHeight()/14), 128, 128, Resources::MasterHand);
	switchPlayers = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth()-150, 0), 100, 100, Resources::NumPlayersSwitch);
	distanceHand = manager->getDefaultWindowHeight() / 14;
	posHand = 0;
}
ExtraMenu::~ExtraMenu()
{
}

void ExtraMenu::selectionUp() {
	if (posHand == 4) {
		posHand = 0;
		hand->setPosition(Vector2D(hand->getPosition().getX(), distanceHand));
	}
	else {
		posHand++;
		hand->setPosition(Vector2D(hand->getPosition().getX(), hand->getPosition().getY()+ manager->getDefaultWindowHeight() / 5.8));
	}
}

void ExtraMenu::selectionDown() {
	if (posHand == 0) {
		posHand = 4;
		hand->setPosition(Vector2D(hand->getPosition().getX(), distanceHand+( (manager->getDefaultWindowHeight() / 5.8)*4)));
	}
	else {
		posHand--;
		hand->setPosition(Vector2D(hand->getPosition().getX(), hand->getPosition().getY() - manager->getDefaultWindowHeight() / 5.8));
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
				manager->getMachine()->changeState(new PlayState(manager, 4, onePlayer, false));
				break;
			case 1:
				manager->getMachine()->changeState(new PlayState(manager, 5, onePlayer, false));
				break;
			case 2:
				manager->getMachine()->changeState(new PlayState(manager, 6, onePlayer, false));
				break;
			case 3:
				manager->getMachine()->changeState(new PlayState(manager, 4, onePlayer, false));
				break;
			case 4:
				manager->getMachine()->changeState(new PlayState(manager, 7, onePlayer, false));
				break;
			default:
				break;
			}

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || event.key.keysym.sym == SDLK_DELETE) {
				
			manager->getMachine()->pushState(new MapState(manager));
				
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) || event.key.keysym.sym == SDLK_DELETE) {
			
			if (switchPlayers->animation.currentFrame == 1) {
				switchPlayers->animation.currentFrame = 0;
				onePlayer = true;
			}
			else {
				switchPlayers->animation.currentFrame = 1;
				onePlayer = false;
			}


		}
	}
	cout << "lul" << endl;

	return false;
}

void ExtraMenu::render(Uint32 time, bool beatSync)
{
		bg->render(time);
		hand->render(time);
		switchPlayers->render(time) ;


	
}
