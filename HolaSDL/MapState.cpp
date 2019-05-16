#include "MapState.h"
#include "GameManager.h"


MapState::MapState(GameManager* g) :GameState(g)
{

	manager->getServiceLocator()->getAudios()->playChannel(Resources::Mapa, -1, 0);
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	createMainButtons();
	fondo__ = new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::Map);
	moreLvls_ = new EmptyObject(g, Vector2D(0, 0), 150, 150, Resources::NivelExtra);

	stage.push_back(fondo__);
	stage.push_back(moreLvls_);

	lockLevels();
	loadGame();

}

MapState::~MapState()
{

}

bool MapState::handleEvent(Uint32 time, SDL_Event e)
{
	if (keyup)
	{
		if (e.type == SDL_CONTROLLERBUTTONDOWN || e.type == SDL_CONTROLLERAXISMOTION) {
			if (!buttons[index].second.selected)
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A)) {
					buttons[index].second.selected = true;
				}
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) {
					nextButton();
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) {
					backButton();
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK)) {
					manager->getServiceLocator()->getAudios()->haltChannel(0);
					manager->getMachine()->changeState(new ExtraMenu(manager));
					return true;
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)) {
					manager->mainmenu = true;
					manager->getServiceLocator()->getAudios()->haltChannel(0);
					manager->getMachine()->changeState(new MainMenuState(manager));
					return true;
				}
				keyup = false;
			}
			else
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP)) {
					buttons[index].second.nextSwitch();
					keyup = false;
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN)) {
					buttons[index].second.prevSwitch();
					keyup = false;
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RETURN) {
					buttons[index].second.selectButton(e, controller);
					keyup = false;
					return true;
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)) {
					buttons[index].second.selected = false;
					keyup = false;
				}
			}
		}
	}
	else if (e.type == SDL_CONTROLLERBUTTONUP)
	{
		keyup = true;
	}

	return GameState::handleEvent(time, e);
}

void MapState::render(Uint32 time, bool beatSync)
{
	GameState::render(time);
	for (auto o : buttons) {
		o.first.render(time, false);
	}
	if (buttons[index].second.selected)
		buttons[index].second.render(time, false);

}

void MapState::lockLevels() {	//resets all the level buttons to be locked and off
	for(int i = 0; i <= max; i++){
		activeLevels[i] = false;
		buttons[i].first.animation = *manager->getServiceLocator()->getTextures()->getAnimation(Resources::MetroOff);
	}
}

void MapState::unlockLevel(int lvl)	//unlocks the level specified in lvl
{
	activeLevels[lvl] = true;
	buttons[lvl].first.animation = *manager->getServiceLocator()->getTextures()->getAnimation(Resources::MetroOn);
}

void MapState::createMainButtons()	//creates all the buttons needed for the levels
{
	
	buttons[0].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 - 60 , manager->getDefaultWindowHeight() / 2 - 30), 64, 64, Resources::MetroOn);
	buttons[1].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 - 260, manager->getDefaultWindowHeight() / 2 - 165), 64, 64, Resources::MetroOff);
	buttons[2].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 + 25 , manager->getDefaultWindowHeight() / 2 + 100), 64, 64, Resources::MetroOff);
	buttons[3].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 + 130, manager->getDefaultWindowHeight() / 2 - 110), 64, 64, Resources::MetroOff);
	buttons[4].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 - 200, manager->getDefaultWindowHeight() / 2 - 85), 64, 64, Resources::MetroOff);
	buttons[0].second = PanelMap(manager, buttons[0].first.getPosition() - Vector2D(200, -20), Resources::CabezaVaporWave, 1, "D35P4C1T0", 1);
	buttons[1].second = PanelMap(manager, buttons[1].first.getPosition(), Resources::CabezaPapito, 2, "Papito Daddy", 2);
	buttons[2].second = PanelMap(manager, buttons[2].first.getPosition() - Vector2D(-30, 110), Resources::EminemciaHead, 3, "Eminemcia", 3);
	buttons[3].second = PanelMap(manager, buttons[3].first.getPosition(), Resources::CabezaZombie, 4, "Corpselillo", 4);
	buttons[4].second = PanelMap(manager, buttons[4].first.getPosition(), Resources::AlienHead, 5, "Onilecram", 5);

	buttons[0].first.scale(2);
}

void MapState::nextButton()	//selects the next level button on the list
{
	buttons[index].first.scale(0.5);

	do {
		virtualIndex++;
	} while (virtualIndex <= max && !activeLevels[levelOrder[virtualIndex]]);

	if (virtualIndex > max)
		virtualIndex = min;

	index = levelOrder[virtualIndex];

	buttons[index].first.scale(2);
}

void MapState::backButton()	//selects the previous level button on the list
{
	buttons[index].first.scale(0.5);

	if (virtualIndex == min)
		virtualIndex = max;

	do {
		virtualIndex--;
	} while (virtualIndex >= min && !activeLevels[levelOrder[virtualIndex]]);

	if (virtualIndex < min)
		virtualIndex = max;


	index = levelOrder[virtualIndex];

	buttons[index].first.scale(2);
}

void MapState::loadGame() {	//reads each level's save file and unlocks them / loads highscores

	//this is to make sure the first level's file is ALWAYS there, even if it's been deleted

	ifstream archivo("resources/data/0.ddb");

	if (!archivo.is_open()) {

		archivo.close();

		ofstream archivo("resources/data/0.ddb");
		archivo << "0 0" << endl << "1 0";
		archivo.close();

	}
	else
		archivo.close();

	unlockLevel(0);

	//simple variable to avoid unlocking levels out of order
	bool stopUnlock = false;

	for (int i = 0; i <= max; i++) {
		string filename = "resources/data/" + to_string(i) + ".ddb";

		ifstream archivo(filename);

		//if the save file exists, then its data is loaded
		if (archivo.is_open()) {
			int mode;
			int scoreE = 0;
			int scoreH = 0;

			archivo >> mode >> scoreE;
			archivo >> mode >> scoreH;
			buttons[i].second.scoreE_ = scoreE;
			buttons[i].second.scoreH_ = scoreH;

			//if the level's highscore is equal to or higher than 600000 (60%), then the difficult mode is unlocked
			if (scoreE >= 600000) {
				buttons[i].second.difActive = true;

				//to make sure the levels are unlocked in order, the precious level's highscore is also checked to be 100% sure it's unlocked
				//If it isn't, then we stop unlocking levels
				if (!stopUnlock && i < max && (i == 0 || (i > 0 && buttons[i - 1].second.scoreE_ >= 600000))) {
					unlockLevel(i + 1);
				}
				else
					stopUnlock = true;
			}
		}

		archivo.close();
	}
}