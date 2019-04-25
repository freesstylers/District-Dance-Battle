#include "EndState.h"

/*EndState::EndState() {
	for (int i = 0;i < 2;i++) {
		buttons[i] = EmptyObject();
	}
	selectedButtons[0] = true;
	selectedButtons[1] = false;
}*/

EndState::EndState(GameManager * g,  int actualScore, int maxScore, int percentage,int lvl): GameState(g)
{
	level = lvl;
	punt = actualScore;
	controller = SDL_GameControllerOpen(0);
	gameManager = g;
	int scoreLimit = (percentage * maxScore)/ 100;
	if (actualScore >= scoreLimit)
		passed = true;
	else
		passed = false;


	points = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::PIXEL10), Vector2D(gameManager->getDefaultWindowWidth() / 2 - 100, 200));
	points->setText("Puntuación final: " + to_string(actualScore), SDL_Color{ (0), (0), (0), (255) });
	points->scale(4);

	EmptyObject* letter = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 + 200, gameManager->getDefaultWindowHeight() / 2), 160, 260, Resources::ScoreS);

	Character* perico = new Character(g, 240, 480, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 200 - 120, 200), Resources::PericoDab);
	perico->isAnimationSynced(false);
	perico->setAnimationFramerate(6);
	
	if (actualScore >= 90 * maxScore/100) {
		perico->forceAnimationChange(Resources::PericoMaxPower);
		letter->forceAnimationChange(Resources::ScoreS);
	}

	else if (actualScore >= 70 * maxScore / 100) {
		letter->forceAnimationChange(Resources::ScoreA);
	}
	
	else if (actualScore >= 50 * maxScore / 100) {
		perico->forceAnimationChange(Resources::PericoDance1);
		letter->forceAnimationChange(Resources::ScoreB);
	}

	else if (actualScore >= 30 * maxScore / 100) {
		perico->forceAnimationChange(Resources::PericoDab);
		letter->forceAnimationChange(Resources::ScoreC);
	}

	else {
		perico->forceAnimationChange(Resources::PericoIdle);
		letter->forceAnimationChange(Resources::ScoreD);
	}

	stage.push_back(new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::MenuBG));
	stage.push_back(letter);
	stage.push_back(perico);

}

EndState::~EndState()
{
	delete points;
}

void EndState::backToMenu(GameManager * gameManager)
{
	gameManager->getMachine()->changeState(new MapState(gameManager));
}

void EndState::render(Uint32 time, bool beatHandler)
{
	GameState::render(time);
	points->render(time);
}


bool EndState::handleEvent(Uint32 time, SDL_Event e)
{
	GameState::handleEvent(time, e);

	bool change = false;
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || e.key.keysym.sym == SDLK_DOWN) {
			nextButton();
			change = true;
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || e.key.keysym.sym == SDLK_UP) {
			backButton();
			change = true;
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN) {
			backToMenu(gameManager);
			change = true;
		}
		return change;
}


void EndState::nextButton()
{
	/*
	buttons[index].first.scale(0.5);
	buttons[index].second = false;
	if (index < max)
	{
		index++;
	}
	else {
		index = min;
	}
	buttons[index].first.scale(2);
	buttons[index].second = true;*/
	
}

void EndState::backButton()
{
	/*buttons[index].first.scale(0.5);
	buttons[index].second = false;
	if (index > min)
	{
		index--;
	}
	else {
		index = max;
	}
	buttons[index].first.scale(2);
	buttons[index].second = true;*/
}
void EndState::renderLetters(Uint32 time, bool beatHandler)
{

	/*Texture msg0(gameManager->getRenderer(),
		types[level],
		*(gameManager->getServiceLocator()->getFonts()->getFont(
			Resources::PIXEL20)), { COLOR(0x00000000) });
	SDL_Rect dest;
	dest.x = gameManager->getWindowWidth() / 4-150;
	dest.y = gameManager->getWindowHeight() / 4-100;
	dest.w = (gameManager->getWindowWidth() / 4);
	dest.h = gameManager->getWindowHeight() / 20;
	msg0.render(gameManager->getRenderer(), dest);

	Texture msg1(gameManager->getRenderer(),
			puntos + to_string(punt) ,*(gameManager->getServiceLocator()->getFonts()->getFont(
				Resources::PIXEL10)), { COLOR(0x00000000) });
	SDL_Rect dest1;
	dest1.x = gameManager->getWindowWidth() / 2-150 ;
	dest1.y = gameManager->getWindowHeight() / 2 ;
	dest1.w = (gameManager->getWindowWidth() / 4);
	dest1.h = gameManager->getWindowHeight() / 20;
	msg1.render(gameManager->getRenderer(), dest1);

	Texture msg2(gameManager->getRenderer(),
		val, *(gameManager->getServiceLocator()->getFonts()->getFont(
			Resources::PIXEL10)), { COLOR(0x00000000) });
	SDL_Rect dest2;
	dest2.x = gameManager->getWindowWidth() / 2 - 150;
	dest2.y = gameManager->getWindowHeight() / 2 +50;
	dest2.w = (gameManager->getWindowWidth() / 4);
	dest2.h = gameManager->getWindowHeight() / 20;
	msg2.render(gameManager->getRenderer(), dest2);*/
	
}
