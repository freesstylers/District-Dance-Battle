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
	distanceHand = manager->getDefaultWindowHeight() / 14 + 15;

	bg = new EmptyObject(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::MenuCanciones);
	hand = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() - 150, distanceHand), 128 * 0.7, 128 * 0.7, Resources::MasterHand);
	switchPlayers = new EmptyObject(manager, Vector2D(50, 0), 102, 90, Resources::NumPlayersSwitch);
	select = new EmptyObject(manager, Vector2D(50, 100), 110, 21, Resources::Select);
	character = new Character(manager, 300 * 0.8, 600 * 0.8, Vector2D((manager->getDefaultWindowWidth() * 0.25) - (300 * 0.5 * 0.9), 10), Resources::RobotIdle);
	character->isAnimationSynced(false);
	character->setAnimationFramerate(4);

	description = new TextObject(manager, manager->getServiceLocator()->getFonts()->getFont(Resources::RETRO20), Vector2D((manager->getDefaultWindowWidth() * 0.05) + 20, manager->getDefaultWindowHeight() - 220 + 20));
	descriptionBox = new EmptyObject(manager, Vector2D((manager->getDefaultWindowWidth() * 0.05), manager->getDefaultWindowHeight() - 220), manager->getDefaultWindowWidth() * 0.4, 175, Resources::ExtraBox);

	initSongs();
	//Leer de archivo la lista de canciones (Titulo >> Artista >> Dificultad >> Numero en menu) y meter en vector
	//Hacer metodo aparte? (pushSongs)
	//Metodo para cambiar los parametros del sprite, descripcion y lista de canciones

}
void ExtraMenu::initSongs()
{
	posHand = 0;
	float posX = 630;
	float posY = manager->getDefaultWindowHeight() / 14 - 10;
	float tamX = 944 * 0.6;
	float tamY = 149 * 0.7;
	float incrY = manager->getDefaultWindowHeight() / 5.8;

	songList.erase(songList.begin(), songList.end());

	switch (currentSinger) {
	case(ROBOT): {
		character->forceAnimationChange(Resources::RobotIdle);
		description->setText("Ignacio huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 17));
		posY += incrY;
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 15));
		posY += incrY;
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "Jose", "lillo", 16));
		posY += incrY;
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 2));
		posY += incrY;
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 9));
		posY += incrY;

		break;
	}
	case(PAPITO): {
		character->forceAnimationChange(Resources::PapitoIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 1));
		posY += incrY;

		break;
	}
	case(EMINEM): {
		character->forceAnimationChange(Resources::EminemciaIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 1));
		posY += incrY;

		break;
	}
	case(CORPSE): {
		character->forceAnimationChange(Resources::ZombieIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 1));
		posY += incrY;

		break;
	}
	case(ALIEN): {
		character->forceAnimationChange(Resources::AlienIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 1));
		posY += incrY;

		break;
	}
	case(NESS): {
		character->forceAnimationChange(Resources::SansIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 1));
		posY += incrY;

		break;
	}
	case(SHREK): {
		character->forceAnimationChange(Resources::ShrekIdle);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 1));
		posY += incrY;

		break;
	}
	case(HONK): {
		character->forceAnimationChange(Resources::GooseDance);
		description->setText("Gonzalo huele mal");

		//añadir canciones
		songList.push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "AA", "BB", 1));
		posY += incrY;

		break;
	}

		/////el resto de cantantes
	}


}
void ExtraMenu::cleanSongs()
{
	songList.erase(songList.begin(), songList.end());
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
	if (posHand == songList.size() - 1) {
		posHand = 0;
		hand->setPosition(Vector2D(hand->getPosition().getX(), distanceHand));
	}
	else {
		posHand++;
		hand->setPosition(Vector2D(hand->getPosition().getX(), hand->getPosition().getY() + manager->getDefaultWindowHeight() / 5.8));
	}
}

void ExtraMenu::selectionDown() {
	if (posHand == 0) {
		posHand = songList.size() - 1;
		hand->setPosition(Vector2D(hand->getPosition().getX(), distanceHand+( (manager->getDefaultWindowHeight() / 5.8)*4)));
	}
	else {
		posHand--;
		hand->setPosition(Vector2D(hand->getPosition().getX(), hand->getPosition().getY() - manager->getDefaultWindowHeight() / 5.8));
	}
}

void ExtraMenu::selectionLeft()
{
	if (currentSinger == ROBOT)
		currentSinger = HONK;	//change if more singers added
	else
		currentSinger--;

	cleanSongs();
	initSongs();
}

void ExtraMenu::selectionRight()
{
	if (currentSinger == HONK)
		currentSinger = ROBOT;	//change if more singers added
	else
		currentSinger++;

	cleanSongs();
	initSongs();
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
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || event.key.keysym.sym == SDLK_LEFT) {

			selectionLeft();

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || event.key.keysym.sym == SDLK_RIGHT) {

			selectionRight();

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE) {
			
			manager->getMachine()->changeState(new PlayState(manager, songList[posHand]->getLevel(), onePlayer, false));

		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_BACKSPACE) {
				
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
		switchPlayers->render(time);
		select->render(time);
		character->render(time);
		descriptionBox->render(time);
		description->render(time);

		for (ExtraSong* s : songList)
			s->render(time);


		hand->render(time);
}
