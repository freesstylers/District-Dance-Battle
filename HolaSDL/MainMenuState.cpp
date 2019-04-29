#include "MainMenuState.h"



MainMenuState::MainMenuState(GameManager*g):GameState(g)
{
	//EmptyObject* icon = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2-100, gameManager->getDefaultWindowHeight() / 2 -200), 300, 300, Resources::MenuIcon);
	buttons[0].first = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 + 325, gameManager->getDefaultWindowHeight() / 2 - 40), 160, 50, Resources::ButtonRestart);
	buttons[1].first = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 + 325, gameManager->getDefaultWindowHeight() / 2 - 40), 160, 50, Resources::ButtonRestart);
	buttons[2].first = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 + 325, gameManager->getDefaultWindowHeight() / 2 - 40), 160, 50, Resources::ButtonOptions);

	buttons[0].second = true;
	buttons[1].second = false;
	buttons[2].second = false;
	//stage.push_back(icon);
	
}


MainMenuState::~MainMenuState()
{
}

void MainMenuState::render(Uint32 time, bool beatHandler)
{
	GameState::render(time);
	for (int i = 0; i < 3; i++)
		buttons[i].first->render(time);
}
