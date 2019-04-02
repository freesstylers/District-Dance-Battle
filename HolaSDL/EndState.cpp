#include "EndState.h"

EndState::EndState(GameManager * g,  int actualScore, int maxScore, int percentage): GameState(g)
{
	int scoreLimit = (percentage * maxScore)/ 100;
	/*int width =
	int height = game->getWindowHeight();*/
	Button* cont = new Button(g, 100, 100, Vector2D(400,200), backToMenu);
	Button* sal = new Button(g, 100, 100, Vector2D(400 ,400 ), exit_);
	Character* perico = new Character(g, 80, 150, Vector2D(400, 150), Resources::PericoDab);
	
	controller = SDL_GameControllerOpen(0);
	if (actualScore >= scoreLimit) {
		perico->forceAnimationChange(Resources::PericoDance1);
		Character*letra = new Character(g, 100, 100, Vector2D(400, 300), Resources::LetraS);
		stage.push_back(letra);
		
	}
	else {
		perico->forceAnimationChange(Resources::PericoDab);
		Character*letra = new Character(g, 100, 100, Vector2D(400, 300), Resources::LetraS);
		stage.push_back(letra);
		//Resources::LetraA;
	}
	stage.push_back(cont);
	stage.push_back(sal);
	stage.push_back(perico);
	
}

EndState::~EndState()
{
}

void EndState::backToMenu(GameManager * gameManager)
{
	gameManager->getMachine()->popState();
}
void EndState::exit_(GameManager* gameManager) {
	gameManager->exit_ = true;
}

/*bool EndState::handleEvent(Uint32 time, SDL_Event e) {
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || e.key.keysym.sym == SDLK_DOWN) {
		nextButton();
	}
	else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || e.key.keysym.sym == SDLK_UP) {
		backButton();
	}
	return GameState::handleEvent(time, e);
}*/

/*void EndState::createButtons()
{
	//deleteButtons();
	int width = 100;
	int height = 100;
	stage.push_back(new Button(gameManager, width, height, Vector2D((2 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getDefaultWindowHeight() / 2 - height / 2),backToMenu(gameManager) ));
	firstButton = stage.begin();
	stage.push_back(new Button(gameManager, width, height, Vector2D((4 * gameManager->getWindowWidth() - gameManager->getWindowWidth()) / 6 - height / 2, gameManager->getDefaultWindowHeight() / 2 - height / 2), exit_(gameManager)));
	selectedButton = firstButton;
	(*selectedButton)->scale(2);
}

void EndState::nextButton()
{
	(*selectedButton)->scale(0.5);
	if ((*selectedButton) != stage.back()) {
		selectedButton++;
	}
	(*selectedButton)->scale(2);
}

void EndState::backButton()
{
	(*selectedButton)->scale(0.5);
	if (selectedButton != firstButton) {
		selectedButton--;
	}
	(*selectedButton)->scale(2);
}*/
