#include "MapState.h"
#include "GameManager.h"


MapState::MapState(GameManager* g) :GameState(g)
{

	manager->getServiceLocator()->getAudios()->playChannel(Resources::Mapa, -1, 0);
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	controller2 = SDL_GameControllerOpen(1);
	createMainButtons();
	fondo__ = new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::Map);
	moreLvls_ = new EmptyObject(g, Vector2D(0, 0), 150, 150, Resources::NivelExtra);

	int aux = Resources::Xbox;
	if (manager->getP1Controller() == 1)
		aux = Resources::Playstation;
	else if (manager->getP1Controller() == 2)
		aux = Resources::fourButtons;
	else if (manager->getP1Controller() == 3)
		aux = Resources::Keyboard;

	selector_ = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() - 190 * 2, 0), 183, 137, aux);
	selectorKeys_ = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() - 190 * 2, 130), 183, 36, Resources::ControlKey1);

	aux = Resources::Xbox;
	if (manager->getP2Controller() == 1)
		aux = Resources::Playstation;
	else if (manager->getP2Controller() == 2)
		aux = Resources::fourButtons;
	else if (manager->getP2Controller() == 3)
		aux = Resources::Keyboard;

	selector2_ = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() - 190, 0), 183, 137, aux);
	selectorKeys2_ = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() - 190, 130), 183, 36, Resources::ControlKey2);

	stage.push_back(fondo__);
	stage.push_back(moreLvls_);
	stage.push_back(selector_);
	stage.push_back(selectorKeys_);
	stage.push_back(selector2_);
	stage.push_back(selectorKeys2_);

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
		if (e.type == SDL_CONTROLLERBUTTONDOWN || e.type == SDL_KEYDOWN) {

			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER)) {
				changeControllerP1(false);
				return true;
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) || e.key.keysym.sym == SDLK_q) {
				changeControllerP1(true);
				return true;
			}
			else if (controller2 != NULL && SDL_GameControllerGetButton(controller2, SDL_CONTROLLER_BUTTON_LEFTSHOULDER)) {
				changeControllerP2(false);
				return true;
			}
			else if ((controller2 != NULL && SDL_GameControllerGetButton(controller2, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)) || e.key.keysym.sym == SDLK_e) {
				changeControllerP2(true);
				return true;
			}


			if (!buttons[index].second.selected)
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_SPACE) {
					buttons[index].second.selected = true;
				}
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RIGHT) {
					nextButton();
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || e.key.keysym.sym == SDLK_LEFT) {
					backButton();
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) || e.key.keysym.sym == SDLK_TAB) {
					manager->getServiceLocator()->getAudios()->haltChannel(0);
					manager->getMachine()->changeState(new ExtraMenu(manager));
					return true;
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_BACKSPACE) {
					manager->mainmenu = true;
					manager->getServiceLocator()->getAudios()->haltChannel(0);
					manager->getMachine()->changeState(new MainMenuState(manager));
					return true;
				}
				keyup = false;
			}
			else
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || e.key.keysym.sym == SDLK_UP) {
					buttons[index].second.nextSwitch();
					keyup = false;
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || e.key.keysym.sym == SDLK_DOWN) {
					buttons[index].second.prevSwitch();
					keyup = false;
				}
				else if ((SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_SPACE) || (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || e.key.keysym.sym == SDLK_LEFT) || (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RIGHT) || e.key.keysym.sym == SDLK_BACKSPACE) {
					buttons[index].second.selectButton(e, controller);
					keyup = false;
					return true;
				}
				else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_BACKSPACE) {
					buttons[index].second.selected = false;
					keyup = false;
				}
			}
		}
	}
	else if (e.type == SDL_CONTROLLERBUTTONUP || e.type == SDL_KEYUP)
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
{							//Since we want the player to move through the map in a circular fashion, there's index (used to select the levels) and virtualIndex (used to select an index from levelOrder[])
	buttons[index].first.scale(0.5);

	if (virtualIndex == max)
		virtualIndex = min;

	else {
		do {
			virtualIndex++;
		} while (virtualIndex <= max && !activeLevels[levelOrder[virtualIndex]]);

		if (virtualIndex > max)
			virtualIndex = min;
	}

	index = levelOrder[virtualIndex];

	buttons[index].first.scale(2);
}

void MapState::backButton()	//selects the previous level button on the list
{							//Since we want the player to move through the map in a circular fashion, there's index (used to select the levels) and virtualIndex (used to select an index from levelOrder[])
	buttons[index].first.scale(0.5);

	if (virtualIndex == min && activeLevels[levelOrder[max]])
		virtualIndex = max;

	else {
		if (virtualIndex == min)
			virtualIndex = max;

		do {
			virtualIndex--;
		} while (virtualIndex >= min && !activeLevels[levelOrder[virtualIndex]]);

		if (virtualIndex < min)
			virtualIndex = max;
	}


	index = levelOrder[virtualIndex];

	buttons[index].first.scale(2);
}

void MapState::changeControllerP1(bool raise)
{
	int P1Controller = manager->getP1Controller(); //

	if (raise)
	{
		if (P1Controller <= 1 || (P1Controller == 2 && manager->getP2Controller() != 3))
		{
			manager->setP1Controller((P1Controller + 1));
		}
		else
		{
			manager->setP1Controller(0);
		}
		P1Controller = manager->getP1Controller();

	}
	else
	{
		if (P1Controller > 0 && P1Controller <= 3)
		{
			manager->setP1Controller((P1Controller - 1));
		}
		else if (P1Controller == 0)
		{
			if (manager->getP2Controller() != 3)
				manager->setP1Controller(3);
			else
				manager->setP1Controller(2);
		}
		P1Controller = manager->getP1Controller();
	}

	changeSelectors();
}

void MapState::changeControllerP2(bool raise)
{
	int P2Controller = manager->getP2Controller(); //

	if (raise)
	{
		if (P2Controller <= 1 || (P2Controller == 2 && manager->getP1Controller() != 3))
		{
			manager->setP2Controller((P2Controller + 1));
		}
		else
		{
			manager->setP2Controller(0);
		}
		P2Controller = manager->getP2Controller();

	}
	else
	{
		if (P2Controller > 0 && P2Controller <= 3)
		{
			manager->setP2Controller((P2Controller - 1));
		}
		else if (P2Controller == 0)
		{
			if (manager->getP1Controller() != 3)
				manager->setP2Controller(3);
			else
				manager->setP2Controller(2);
		}
		P2Controller = manager->getP2Controller();
	}

	changeSelectors();
}

void MapState::changeSelectors()
{
	int aux = Resources::Xbox;
	if (manager->getP1Controller() == 1)
		aux = Resources::Playstation;
	else if (manager->getP1Controller() == 2)
		aux = Resources::fourButtons;
	else if (manager->getP1Controller() == 3)
		aux = Resources::Keyboard;

	selector_->forceAnimationChange(aux);

	aux = Resources::Xbox;
	if (manager->getP2Controller() == 1)
		aux = Resources::Playstation;
	else if (manager->getP2Controller() == 2)
		aux = Resources::fourButtons;
	else if (manager->getP2Controller() == 3)
		aux = Resources::Keyboard;

	selector2_->forceAnimationChange(aux);

	manager->updateOptionsFile();
}

void MapState::loadGame() {	//reads each level's save file and unlocks them / loads highscores

	//this is to make sure the first and second level's files are ALWAYS there, even if they've been deleted

	ifstream a("resources/data/0.ddb");

	if (!a.is_open()) {

		a.close();

		ofstream o("resources/data/0.ddb");
		o << "0 0" << endl << "1 0";
		o.close();

	}
	else
		a.close();
	
	ifstream b("resources/data/1.ddb");

	if (!b.is_open()) {

		b.close();

		ofstream o("resources/data/1.ddb");
		o << "0 0" << endl << "1 0";
		o.close();

	}
	else
		b.close();

	unlockLevel(0);
	unlockLevel(1);

	for (int i = 0; i <= max; i++) {
		string filename = "resources/data/" + to_string(i+1) + ".ddb";

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

				//the levels are also unlocked in pairs, so we need to check every odd level and the one before it
				if (i < max && i % 2 == 1 && buttons[i - 1].second.scoreE_ >= 600000) {
					unlockLevel(i + 1);
					if(i + 2 < max)
						unlockLevel(i + 2);
				}
			}
		}

		archivo.close();
	}
}