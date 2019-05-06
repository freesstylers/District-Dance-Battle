#include "MainMenuState.h"



MainMenuState::MainMenuState(GameManager*g):GameState(g)
{
	gameManager = g;
	controller = SDL_GameControllerOpen(0);
	EmptyObject* icon = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2-100, gameManager->getDefaultWindowHeight() / 2 -100), 200, 200, Resources::MenuIcon);
	buttons[0].first = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 , gameManager->getDefaultWindowHeight() /2+50), 160, 50, Resources::ButtonRestart);
	buttons[1].first = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 , gameManager->getDefaultWindowHeight() / 2+150), 160, 50, Resources::ButtonRestart);
	buttons[2].first = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 , gameManager->getDefaultWindowHeight() /2+250), 160, 50, Resources::ButtonRestart);

	buttons[0].second = true;
	buttons[1].second = false;
	buttons[2].second = false;

	buttons[0].first->scale(2);
	stage.push_back(icon);
	
}


MainMenuState::~MainMenuState()
{
	for (int i = 0; i < 3; i++)
	{
		delete buttons[i].first;
		buttons[i].first = nullptr;
	}

}

void MainMenuState::render(Uint32 time, bool beatHandler)
{
	GameState::render(time);
	for (int i = 0; i < 3; i++)
		buttons[i].first->render(time);
}

void MainMenuState::nextButton() 
{
	
	buttons[index].first->scale(0.5);
	buttons[index].second = false;
	if (index < max)
	{
		index++;
	}
	else {
		index = min;
	}
	buttons[index].first->scale(2);
	buttons[index].second = true;
}
void MainMenuState::backButton()
{

	buttons[index].first->scale(0.5);
	buttons[index].second = false;
	if (index > min)
	{
		index--;
	}
	else {
		index = max;
	}
	buttons[index].first->scale(2);
	buttons[index].second = true;
}

void MainMenuState::newGame(GameManager* gameManager) 
{
	gameManager->getMachine()->changeState(new MapState(gameManager));
}

bool MainMenuState::handleEvent(Uint32 time, SDL_Event e) 
{
	bool input = false;
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || e.key.keysym.sym == SDLK_DOWN)
	{
		nextButton();
		input = true;
	}
	else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || e.key.keysym.sym == SDLK_UP)
	{
		backButton();
		input = true;
	}
	else if (buttons[0].second == true && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_SPACE))
	{
		newGame(gameManager);
		input = true;
	}
	return input;
}
