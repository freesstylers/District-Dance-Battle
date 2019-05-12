#include "MapState.h"
#include "GameManager.h"


MapState::MapState(GameManager* g) :GameState(g)
{
	g->getServiceLocator()->getAudios()->setChannelVolume(60, 1);
	g->getServiceLocator()->getAudios()->setChannelVolume(40, 0);

	manager->getServiceLocator()->getAudios()->playChannel(Resources::Mapa, -1, 0);
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	createMainButtons();
	fondo__ = new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::Map);

	moreLvls_ = new EmptyObject(g, Vector2D(0, 0), 150, 150, Resources::NivelExtra);
	stage.push_back(fondo__);
	stage.push_back(moreLvls_);
	//activeLevels = { true, true, true, true, true };
	unlockLevel(0);
	unlockLevel(1);
	unlockLevel(2);
	unlockLevel(3);
	unlockLevel(4);
	loadGame();
}

MapState::~MapState()
{

}

bool MapState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.type == SDL_CONTROLLERBUTTONDOWN && keyup || e.type == SDL_KEYDOWN && keyup || e.type == SDL_CONTROLLERAXISMOTION && keyup) {
		if(!buttons[index].second.selected)
		{
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN) {
				buttons[index].second.selected = true;
			}
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RIGHT) {
				//buttons[index].second.reset();
				nextButton();
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || e.key.keysym.sym == SDLK_LEFT) {
				//buttons[index].second.reset();
				backButton();
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) || e.key.keysym.sym == SDLK_TAB) {
				manager->getMachine()->pushState(new ExtraMenu(manager));
				manager->getServiceLocator()->getAudios()->haltChannel(0);
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || e.key.keysym.sym == SDLK_TAB) {
				manager->mainmenu = true;
				manager->getMachine()->pushState(new MainMenuState(manager));
				manager->getServiceLocator()->getAudios()->haltChannel(0);
			}
		}
		else
		{
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || e.key.keysym.sym == SDLK_UP) {
				buttons[index].second.nextSwitch();
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || e.key.keysym.sym == SDLK_DOWN) {
				buttons[index].second.prevSwitch();
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RETURN) {
				buttons[index].second.selectButton(e, controller);
				return true;
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || e.key.keysym.sym == SDLK_DELETE) {
				buttons[index].second.selected = false;
			}
			
		}
		keyup = false;
	}
	else if (e.type == SDL_CONTROLLERBUTTONUP) keyup = true;

	else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_F10) {
		manager->getServiceLocator()->getAudios()->haltChannel(0);
		manager->getMachine()->changeState(new TutorialState(manager));
		return true;
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

void MapState::unlockLevel(int lvl)
{
	activeLevels[lvl] = true;
	buttons[lvl].first.animation = *manager->getServiceLocator()->getTextures()->getAnimation(Resources::MetroOn);
}

void MapState::createMainButtons()
{
	
	buttons[0].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 - 60 , manager->getDefaultWindowHeight() / 2 - 30), 64, 64, Resources::MetroOn);
	buttons[1].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 - 260, manager->getDefaultWindowHeight() / 2 - 165), 64, 64, Resources::MetroOn);
	buttons[2].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 + 25 , manager->getDefaultWindowHeight() / 2 + 100), 64, 64, Resources::MetroOff);
	buttons[3].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 + 130, manager->getDefaultWindowHeight() / 2 - 110), 64, 64, Resources::MetroOff);
	buttons[4].first = EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 - 200, manager->getDefaultWindowHeight() / 2 - 85), 64, 64, Resources::MetroOff);
	buttons[0].second = PanelMap(manager, buttons[0].first.getPosition() - Vector2D(200, -20), Resources::CabezaVaporWave, 1, "D35P4C1T0", 1);
	buttons[1].second = PanelMap(manager, buttons[1].first.getPosition(), Resources::CabezaPapito, 2, "Papito Daddy", 3);
	buttons[2].second = PanelMap(manager, buttons[2].first.getPosition() - Vector2D(-30, 110), Resources::EminemciaHead, 3, "Eminemcia", 2);
	buttons[3].second = PanelMap(manager, buttons[3].first.getPosition(), Resources::CabezaZombie, 4, "Corpselillo", 4);
	buttons[4].second = PanelMap(manager, buttons[4].first.getPosition(), Resources::EminemciaHead, 5, "Eminemcia", 5);

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

void MapState::unlockLevels()
{
	for(int i = 0; i < 4; i++)
	{
		buttons[i].second.difActive = buttons[i].second.scoreE_ > 800000;
	}
	if (buttons[2].second.scoreE_ > 600000 && buttons[3].second.scoreE_ > 600000) {
		unlockLevel(4);
	}
	if (buttons[1].second.scoreE_ > 600000 && buttons[0].second.scoreE_ > 600000) {
		unlockLevel(2);
		unlockLevel(3);
	}
	int i = 0;
	while (buttons[i].second.scoreH_ > 800000) {
		i++;
	}
	if (i >= 4) { buttons[i].second.difActive = true; }
}

//Leemos de un arhcivo  la dificultad, los puntos obtenidos
void MapState::loadGame() {

	for (int i = 0; i <= 4; i++) {
		string filename = "resources/data/" + to_string(i+1) + ".txt";

		ifstream archivo(filename);

		//
		int mode;
		int scoreE = 0;
		int scoreH = 0;

		archivo >> mode >> scoreE;
		archivo >> mode >> scoreH;
		buttons[i].second.scoreE_ = scoreE;
		buttons[i].second.scoreH_ = scoreH;

		archivo.close();

	}
	unlockLevels();
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


