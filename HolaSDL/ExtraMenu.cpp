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
	songList = vector<vector<ExtraSong*>>(8);
	distanceHand = manager->getDefaultWindowHeight() / 14 + 15;

	bg = new EmptyObject(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::MenuCanciones);
	hand = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() - 150, distanceHand), 128 * 0.7, 128 * 0.7, Resources::MasterHand);
	switchPlayers = new EmptyObject(manager, Vector2D(50, 0), 102, 90, Resources::NumPlayersSwitch);
	select = new EmptyObject(manager, Vector2D(50, 100), 110, 21, Resources::Select);
	character = new Character(manager, 300 * 0.8, 600 * 0.8, Vector2D((manager->getDefaultWindowWidth() * 0.25) - (300 * 0.5 * 0.8), 10), Resources::RobotIdle);
	character->isAnimationSynced(false);
	character->setAnimationFramerate(4);

	descriptionBox = new EmptyObject(manager, Vector2D((manager->getDefaultWindowWidth() * 0.07), manager->getDefaultWindowHeight() - 220), manager->getDefaultWindowWidth() * 0.4, 175, Resources::ExtraBox);
	arrowL = new EmptyObject(manager, Vector2D((manager->getDefaultWindowWidth() * 0.23 - 225), manager->getDefaultWindowHeight() * 0.35), 96, 96, Resources::Left);
	arrowR = new EmptyObject(manager, Vector2D((manager->getDefaultWindowWidth() * 0.23 + 225), manager->getDefaultWindowHeight() * 0.35), 96, 96, Resources::Right);

	initSongs();
	//Leer de archivo la lista de canciones (Titulo >> Artista >> Dificultad >> Numero en menu) y meter en vector
	//Hacer metodo aparte? (pushSongs)
	//Metodo para cambiar los parametros del sprite, descripcion y lista de canciones

}
void ExtraMenu::initSongs()
{
	posHand = 0;
	float posX = 630;
	float posYOrig = manager->getDefaultWindowHeight() / 14 - 10;
	float posY = manager->getDefaultWindowHeight() / 14 - 10;
	float tamX = 944 * 0.6;
	float tamY = 149 * 0.7;
	float incrY = manager->getDefaultWindowHeight() / 5.8;

	hand->setPosition(Vector2D(hand->getPosition().getX(), distanceHand));

	//case(ROBOT)
		character->forceAnimationChange(Resources::RobotIdle);
		//a�adir canciones
		songList[0].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "Cancion de testeo", "BB", 20));
		posY += incrY;
		songList[0].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "Never Gonna Give You Up", "Rick Astley", 10));
		posY += incrY;

		posY = posYOrig;
	//case(PAPITO)

		//a�adir canciones
		songList[1].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "Cumbia de los Vengadores", "Cumbia Drive", 17));
		posY += incrY;
		songList[1].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraNormal, "DotA", "Basshunter", 13));
		posY += incrY;

		posY = posYOrig;
		//case(EMINEM)

		//a�adir canciones
		songList[2].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraNormal, "Asereje", "Las Ketchup", 11));
		posY += incrY;

		posY = posYOrig;
		//case(CORPSE)

		//a�adir canciones
		songList[3].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraDificil, "At Doom's Gate", "Andrew Hulshult", 16));
		posY += incrY;

		posY = posYOrig;
		//case(ALIEN)

		//a�adir canciones
		songList[4].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "Rasputin (Funk Remix)", "Boney M", 19));
		posY += incrY;
		songList[4].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraDificil, "Running in the 90s", "Maurizio De Jorio", 8));
		posY += incrY;
		songList[4].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraDificil, "Tripoloski", "Davay", 15));
		posY += incrY;

		posY = posYOrig;
		//case(NESS)

		//a�adir canciones
		songList[5].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "Dracukeo", "Kidd Keo", 18));
		posY += incrY;
		songList[5].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraDificil, "Megalovania", "Toby Fox", 7));
		posY += incrY;

		posY = posYOrig;
		//case(SHREK)

		//a�adir canciones
		songList[6].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraFacil, "Doraemon Galego", "Xabarin Club", 14));
		posY += incrY;
		songList[6].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraNormal, "All Star", "Smash Mouth", 6));
		posY += incrY;

		posY = posYOrig;
		//case(HONK)

		//a�adir canciones
		songList[7].push_back(new ExtraSong(manager, Vector2D(posX, posY), tamX, tamY, Resources::CancionExtraDificil, "Megalovania (Honk Remix)", "Toby Fox", 12));
		posY += incrY;


		/////el resto de cantantes

		std::ifstream file("resources/dialog/descriptions.txt");
		if (file.is_open()) {
			std::string line;
			int i = 0;
			while (getline(file, line)) {
				description.push_back(new TextObject(manager, manager->getServiceLocator()->getFonts()->getFont(Resources::RETRO16), Vector2D((manager->getDefaultWindowWidth() * 0.07) + 20, manager->getDefaultWindowHeight() - 220 + 20)));
				description[i]->setText(line, SDL_Color{ (255), (255), (255), (255) }, manager->getDefaultWindowWidth() * 0.4 - 50);
				i++;
			}
			file.close();
		}

}
void ExtraMenu::cleanStuff()
{
	for(vector<ExtraSong*> v : songList)
		v.erase(v.begin(), v.end());
	songList.erase(songList.begin(), songList.end());

	for (TextObject* t : description)
		delete t;
	description.erase(description.begin(), description.end());
}
void ExtraMenu::updateSinger()
{
	posHand = 0;
	hand->setPosition(Vector2D(hand->getPosition().getX(), distanceHand));

	switch (currentSinger) {
	case(ROBOT): {
		character->forceAnimationChange(Resources::RobotIdle);
		break;
	}
	case(PAPITO): {
		character->forceAnimationChange(Resources::PapitoIdle);
		break;
	}
	case(EMINEM): {
		character->forceAnimationChange(Resources::EminemciaIdle);
		break;
	}
	case(CORPSE): {
		character->forceAnimationChange(Resources::ZombieIdle);
		break;
	}
	case(ALIEN): {
		character->forceAnimationChange(Resources::AlienIdle);
		break;
	}
	case(NESS): {
		character->forceAnimationChange(Resources::SansIdle);
		break;
	}
	case(SHREK): {
		character->forceAnimationChange(Resources::ShrekIdle);
		break;
	}
	case(HONK): {
		character->forceAnimationChange(Resources::GooseDance);
		break;
	}
	}
}
ExtraMenu::~ExtraMenu()
{
	delete bg;
	delete hand;
	delete switchPlayers;
	delete select;
	delete character;
	delete arrowL;
	delete arrowR;

	cleanStuff();

	bg = nullptr;
	hand = nullptr;
	switchPlayers = nullptr;
	select = nullptr;
	character = nullptr;
	arrowL = nullptr;
	arrowR = nullptr;
}

void ExtraMenu::selectionUp() {
	if (posHand == songList[currentSinger].size() - 1) {
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
		posHand = songList[currentSinger].size() - 1;
		hand->setPosition(Vector2D(hand->getPosition().getX(), distanceHand + ((manager->getDefaultWindowHeight() / 5.8) * posHand)));
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

	updateSinger();
}

void ExtraMenu::selectionRight()
{
	if (currentSinger == HONK)
		currentSinger = ROBOT;	//change if more singers added
	else
		currentSinger++;

	updateSinger();
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
			
			manager->getMachine()->changeState(new PlayState(manager, songList[currentSinger][posHand]->getLevel(), onePlayer, false));

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
		description[currentSinger]->render(time);
		arrowR->render(time);
		arrowL->render(time);

		for (ExtraSong* s : songList[currentSinger])
			s->render(time);


		hand->render(time);
}
