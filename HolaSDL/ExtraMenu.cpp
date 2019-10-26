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

	bg = new EmptyObject(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::MenuCanciones);
	hand = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth()-400, manager->getDefaultWindowHeight()/14), 128, 128, Resources::MasterHand);
	switchPlayers = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth()-150, 0), 102, 90, Resources::NumPlayersSwitch);
	select = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() - 150-10, 100), 110, 21, Resources::Select);
	distanceHand = manager->getDefaultWindowHeight() / 14;
	character = new Character(manager, 300, 600, Vector2D(60, 90), Resources::RobotIdle);
	character->isAnimationSynced(false);
	character->setAnimationFramerate(4);

	initSongs();
	//Leer de archivo la lista de canciones (Titulo >> Artista >> Dificultad >> Numero en menu) y meter en vector
	//Hacer metodo aparte? (pushSongs)
	//Metodo para cambiar los parametros del sprite, descripcion y lista de canciones

}
void ExtraMenu::initSongs()
{
	posHand = 0;

	description = new TextObject(manager, manager->getServiceLocator()->getFonts()->getFont(Resources::RETRO20), Vector2D(70, 650));
	descriptionBox = new EmptyObject(manager, Vector2D(346 / 2, 70), 346, 145, Resources::ExtraBox);

	switch (currentSinger) {
	case(ROBOT): {
		character->forceAnimationChange(Resources::RobotIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(10, 10), 50, 50, Resources::CancionExtraFacil, "AA", "BB", 1));
		break;
	}
	case(PAPITO): {
		character->forceAnimationChange(Resources::PapitoIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(10, 10), 50, 50, Resources::CancionExtraFacil, "AA", "BB", 1));
		break;
	}
	case(EMINEM): {
		character->forceAnimationChange(Resources::EminemciaIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(10, 10), 50, 50, Resources::CancionExtraFacil, "AA", "BB", 1));
		break;
	}
	case(CORPSE): {
		character->forceAnimationChange(Resources::ZombieIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(10, 10), 50, 50, Resources::CancionExtraFacil, "AA", "BB", 1));
		break;
	}
	case(ALIEN): {
		character->forceAnimationChange(Resources::AlienIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(10, 10), 50, 50, Resources::CancionExtraFacil, "AA", "BB", 1));
		break;
	}
	case(NESS): {
		character->forceAnimationChange(Resources::SansIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(10, 10), 50, 50, Resources::CancionExtraFacil, "AA", "BB", 1));
		break;
	}
	case(SHREK): {
		character->forceAnimationChange(Resources::ShrekIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(10, 10), 50, 50, Resources::CancionExtraFacil, "AA", "BB", 1));
		break;
	}

		/////el resto de cantantes
	}


}
ExtraMenu::~ExtraMenu()
{
	delete bg;
	delete hand;
	delete switchPlayers;
	delete select;
	delete character;
	delete description;

	songList.erase(songList.begin(), songList.end());

	bg = nullptr;
	hand = nullptr;
	switchPlayers = nullptr;
	select = nullptr;
	character = nullptr;
	description = nullptr;
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
	GameState::handleEvent(time, event);

	if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || event.key.keysym.sym == SDLK_UP) {
			
			selectionDown();

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || event.key.keysym.sym == SDLK_DOWN) {

			selectionUp();

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || event.key.keysym.sym == SDLK_w) {
			
			switch (posHand)
			{
			case 0:
				manager->getMachine()->changeState(new PlayState(manager, 13, onePlayer, false));
				break;
			case 1:
				manager->getMachine()->changeState(new PlayState(manager, 11, onePlayer, false));
				break;
			case 2:
				manager->getMachine()->changeState(new PlayState(manager, 6, onePlayer, false));
				break;
			case 3:
				manager->getMachine()->changeState(new PlayState(manager, 8, onePlayer, false));
				break;
			case 4:
				manager->getMachine()->changeState(new PlayState(manager, 7, onePlayer, false));
				break;
			default:
				break;
			}

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || event.key.keysym.sym == SDLK_s) {
				
			manager->getMachine()->pushState(new MapState(manager));
				
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) || event.key.keysym.sym == SDLK_BACKSPACE) {
			
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

	return false;
}

void ExtraMenu::render(Uint32 time, bool beatSync)
{
		bg->render(time);
		hand->render(time);
		switchPlayers->render(time);
		select->render(time);
		character->render(time);
		description->render(time);
		descriptionBox->render(time);

		for (ExtraSong* s : songList)
			s->render(time);
}
