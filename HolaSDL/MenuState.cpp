#include "MenuState.h"


MenuState::MenuState(GameManager* g) :GameState(g)
{
	gameManager = g;
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
	/*int width = 100;
	int height = 100;
	stage.push_back(new Button(gameManager, width, height, Vector2D((2 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getDefaultWindowHeight() / 2 - height / 2), play));
	firstButton = stage.begin();
	stage.push_back(new Button(gameManager, width, height, Vector2D((4 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getDefaultWindowHeight() / 2 - height / 2), play));
	stage.push_back(new Button(gameManager, width, height, Vector2D((6 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getDefaultWindowHeight() / 2 - height / 2), createButtons));
	selectedButton = firstButton;
	(*selectedButton)->scale(2);*/
	createMainButtons();
}

MenuState::~MenuState()
{
}

bool MenuState::handleEvent(Uint32 time, SDL_Event e)
{
	//if (e.type == SDL_CONTROLLERBUTTONDOWN) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || e.key.keysym.sym == SDLK_RIGHT) {
			nextButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || e.key.keysym.sym == SDLK_LEFT) {
			backButton();
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A)|| e.key.keysym.sym == SDLK_RETURN) {
			static_cast<Button*>((*selectedButton))->callCallback();
		}else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)|| e.key.keysym.sym == SDLK_DELETE) {
			createMainButtons();
		}
	//}
	return GameState::handleEvent(time, e);
}

void MenuState::deleteButtons()
{
	if (!stage.empty()) {
		selectedButton = firstButton;
		auto it = selectedButton;
		while (selectedButton != stage.end()) {
			it++;
			stage.erase(selectedButton);
			selectedButton = it;
		}
	}
}

void MenuState::createMainButtons()
{
	deleteButtons();
	int width = 100;
	int height = 100;
	stage.push_back(new Button(gameManager, width, height, Vector2D((2 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getDefaultWindowHeight() / 2 - height / 2), play));
	firstButton = stage.begin();
	stage.push_back(new Button(gameManager, width, height, Vector2D((4 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getDefaultWindowHeight() / 2 - height / 2), play));
	stage.push_back(new Button(gameManager, width, height, Vector2D((6 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getDefaultWindowHeight() / 2 - height / 2), createButtons));
	selectedButton = firstButton;
	(*selectedButton)->scale(2);
}

void MenuState::nextButton()
{
	(*selectedButton)->scale(0.5);
	if ((*selectedButton) != stage.back()) {
		selectedButton++;
	}
	(*selectedButton)->scale(2);
}

void MenuState::backButton()
{
	(*selectedButton)->scale(0.5);
	if (selectedButton != firstButton) {
		selectedButton--;
	}
	(*selectedButton)->scale(2);
}

void MenuState::play(GameManager* game) {
	cout << "jugando" << endl;
	//game->getMachine()->pushState(new PlayState(game, ));
}

void MenuState::createButtons(GameManager * gameManager)
{
	static_cast<MenuState*>(gameManager->getMachine()->currentState())->deleteButtons();
	int width = 50;
	int height = 50;
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((4 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getDefaultWindowHeight() / 3 - height / 2), play));
	static_cast<MenuState*>(gameManager->getMachine()->currentState())->firstButton = gameManager->getMachine()->currentState()->stage.begin();
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((5 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getDefaultWindowHeight() / 3 - height / 2), play));
	gameManager->getMachine()->currentState()->stage.push_back(new Button(gameManager, width, height, Vector2D((6 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - width / 2, gameManager->getDefaultWindowHeight() / 3 - height / 2), play));
	static_cast<MenuState*>(gameManager->getMachine()->currentState())->selectedButton = static_cast<MenuState*>(gameManager->getMachine()->currentState())->firstButton;
	(*static_cast<MenuState*>(gameManager->getMachine()->currentState())->selectedButton)->scale(2);

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