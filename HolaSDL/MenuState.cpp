#include "MenuState.h"


MenuState::MenuState(GameManager* g) :GameState(g)
{
	gameManager = g;
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	createMainButtons();
}

MenuState::~MenuState()
{
}

bool MenuState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.type == SDL_CONTROLLERBUTTONDOWN) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RIGHT) {
			nextButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || e.key.keysym.sym == SDLK_LEFT) {
			backButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A)|| e.key.keysym.sym == SDLK_RETURN) {
			buttonUse();
		}else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)|| e.key.keysym.sym == SDLK_DELETE) {
			reset();
		}
	}
	return GameState::handleEvent(time, e);
}

void MenuState::render(Uint32 time, bool beatSync)
{
	GameState::render(time);
	for (auto o : buttons) {
		o.render(time, false);
	}
}

void MenuState::createMainButtons()
{
	int ang = 360 / 5;
	int angIni = 270;
	int angulo;
	int r =  150;
	for (int i = 0; i < 5; i++) {
		angulo = angIni + ang * i;
		buttons[i] = EmptyObject(gameManager, Vector2D((gameManager->getWindowWidth()/2 + r * cos(((angulo*M_PI)/180)))-25, (gameManager->getWindowHeight()/2 + r * sin(((angulo*M_PI) / 180)))-25), 50, 50, Resources::YButton);
	}
	buttons[5] = EmptyObject(gameManager, Vector2D(50, 100), 100, 50, Resources::YButton);
	buttons[6] = EmptyObject(gameManager, Vector2D(150, 100), 100, 50, Resources::YButton);
	buttons[7] = EmptyObject(gameManager, Vector2D(50, 150), 100, 50, Resources::YButton);
	buttons[8] = EmptyObject(gameManager, Vector2D(150, 150), 100, 50, Resources::YButton);
	buttons[9] = EmptyObject(gameManager, Vector2D(50, 200), 100, 50, Resources::YButton);
	buttons[10] = EmptyObject(gameManager, Vector2D(150, 200), 100, 50, Resources::YButton);
	buttons[11] = EmptyObject(gameManager, Vector2D(50, 250), 100, 50, Resources::YButton);
	buttons[12] = EmptyObject(gameManager, Vector2D(150, 250), 100, 50, Resources::YButton);
	buttons[13] = EmptyObject(gameManager, Vector2D(50, 300), 100, 50, Resources::YButton);
	buttons[14] = EmptyObject(gameManager, Vector2D(150, 300), 100, 50, Resources::YButton);

	reset();

	buttons[0].scale(2);
}

void MenuState::nextButton()
{
	buttons[index].scale(0.5);
	if (index < max) {
		index++;
	}
	else {
		index = min;
	}
	buttons[index].scale(2);
}

void MenuState::backButton()
{
	buttons[index].scale(0.5);
	if (index > min) {
		index--;
	}
	else {
		index = max;
	}
	buttons[index].scale(2);
}

void MenuState::reset() {
	//if(buttons[0].)
	deactivateAll();
	activate(0, 4);
}

void MenuState::deactivateAll() {
	for (int i = 0; i < 15; i++) {
		buttons[i].setActive(false);
	}
}

void MenuState::activate(int first, int last) {

	deactivateAll();

	buttons[index].scale(0.5);

	for (int i = first; i <= last; i++) {
		buttons[i].setActive(true);
	}
	
	min = first;
	index = min;
	max = last;

	buttons[index].scale(2);
}

void MenuState::buttonUse() {
	switch (index) {
	case 0: case 1: case 2: case 3: case 4:
		activate(2*index + 5, 2*index + 6);
		break;
	case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
		play(gameManager);
		break;
	}
}

void MenuState::play(GameManager* game) {
	cout << "jugando" << endl;
	game->getMachine()->pushState(new PlayState(game));
}


void MenuState::load(GameManager* game)
{
	cout << "cargando" << endl;
	//game->getMachine()->pushState(new PlayState(game, 1));
}

void MenuState::exit(GameManager* game)
{
	cout << "saliendo" << endl;
	//game->exit();
}

///////////////////////////////////////////////////////////////////////

/*

//new game

//load game

//settings

//exit

//others?

*/