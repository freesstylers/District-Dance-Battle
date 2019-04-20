#include "MapState.h"
#include "GameManager.h"


MapState::MapState(GameManager* g) :GameState(g)
{
	manager->getServiceLocator()->getAudios()->playChannel(Resources::Mapa, 1);
	manager->getServiceLocator()->getAudios()->setChannelVolume(70);
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	createMainButtons();
	fondo__ = new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::Map);
	stage.push_back(fondo__);
	activeLevels[0] = true;
	activeLevels[1] = true;
	loadGame();
}

MapState::~MapState()
{

}

bool MapState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.type == SDL_CONTROLLERBUTTONDOWN || e.type == SDL_KEYDOWN) {
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
		}
		else
		{
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || e.key.keysym.sym == SDLK_UP) {
				buttons[index].second.nextSwitch();
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || e.key.keysym.sym == SDLK_DOWN) {
				buttons[index].second.prevSwitch();
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN) {
				buttons[index].second.selectButton();
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || e.key.keysym.sym == SDLK_DELETE) {
				buttons[index].second.selected = false;
			}
		}
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

void MapState::createMainButtons()
{
	buttons[0].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 - 50 , manager->getWindowHeight() / 2 - 30), 64, 64, Resources::MetroOn);
	buttons[1].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 + 25 , manager->getWindowHeight() / 2 + 100), 64, 64, Resources::MetroOn);
	buttons[2].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 + 75 , manager->getWindowHeight() / 2 - 85), 64, 64, Resources::MetroOn);
	buttons[3].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 - 180, manager->getWindowHeight() / 2 - 125), 64, 64, Resources::MetroOn);
	buttons[4].first = EmptyObject(manager, Vector2D(manager->getWindowWidth() / 2 - 150, manager->getWindowHeight() / 2 - 75), 64, 64, Resources::MetroOn);
	buttons[0].second = PanelMap(manager, buttons[0].first.getPosition() - Vector2D(200, -20), Resources::CabezaVaporWave, 1, "D35P4C1T0", 1);
	buttons[1].second = PanelMap(manager, buttons[1].first.getPosition() - Vector2D(-30, 110), Resources::EminemciaHead, 3, "Eminemcia", 2);
	buttons[2].second = PanelMap(manager, buttons[2].first.getPosition(), Resources::CabezaVaporWave, 1, "D35P4C1T0", 1);
	buttons[3].second = PanelMap(manager, buttons[3].first.getPosition(), Resources::EminemciaHead, 3, "Eminemcia", 2);
	buttons[4].second = PanelMap(manager, buttons[4].first.getPosition(), Resources::CabezaVaporWave, 1, "D35P4C1T0", 1);

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
		buttons[i].second.difActive = buttons[i].second.noteP1E_ == 'S' || buttons[i].second.noteP1E_ == 'A' || buttons[i].second.noteP2E_ == 'A' || buttons[i].second.noteP2E_ == 'S';
	}
	if (buttons[2].second.difActive && buttons[3].second.difActive) {
		activeLevels[4] = true;
	}
	else if (buttons[1].second.difActive && buttons[0].second.difActive) {
		activeLevels[2] = true;
		activeLevels[3] = true;
	}
	int i = 0;
	while (buttons[i].second.hardModeCompleted) {
		i++;
	}
	if (i >= 4) { buttons[i].second.difActive = true; }
}

//Leemos de un arhcivo el nivel, la dificultad, el numero de jugadores los puntos obtenidos y la nota obtenida
void MapState::loadGame() {
	ifstream archivo("partida.txt");
	string line;
	int level;
	int mode;
	int players;
	int points;
	char note;
	while (getline(archivo, line)) {
		archivo >> level >> mode >> players; //Primero se lee el nivel, la dificultad y los jugadores para guardar los numeros
		activeLevels[level - 1] = true;
		if (mode == 0) {
			/*buttons[level - 1].second.difActive = true;					*/
			archivo >> points >> note;
			if (buttons[level - 1].second.scoreP1E_ <= points) {
				buttons[level - 1].second.scoreP1E_ = points;
				buttons[level - 1].second.noteP1E_ = note;
			}
			if (players == 2) {
				archivo >> points >> note;
				if (buttons[level - 1].second.scoreP2E_ <= points) {
					buttons[level - 1].second.scoreP2E_ = points;
					buttons[level - 1].second.noteP2E_ = note;
				}
			}
		}
		else {
			buttons[level - 1].second.difActive = true;
			archivo >> points >> note;
			buttons[level - 1].second.scoreP1H_ = points;
			buttons[level - 1].second.noteP1H_ = note;
			if (players == 2) {
				archivo >> points >> note;
				buttons[level - 1].second.scoreP2H_ = points;
				buttons[level - 1].second.noteP2H_ = note;
			}
		}
	}
	archivo.close();
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


