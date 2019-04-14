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
	EmptyObject* letter;
	Character* perico = new Character(g, 150, 275, Vector2D(gameManager->getWindowWidth()/2-30,gameManager->getWindowHeight()/4-130), Resources::PericoDab);
	buttons[0].first=EmptyObject(g,Vector2D(g->getWindowWidth() / 2-75 , g->getWindowHeight() / 4*2.75 ), 150, 50,Resources::BackMap);
	buttons[1].first=EmptyObject(g, Vector2D(g->getWindowWidth() / 2-75, g->getWindowHeight()/4 *3.25), 150, 50, Resources::Exit);
	buttons[0].second = true;
	buttons[1].second = false;
	buttons[0].first.scale(2);
	
	if (actualScore >= 80*maxScore/100) {
		perico->forceAnimationChange(Resources::PericoDab);
		letter = new EmptyObject(g, Vector2D(gameManager->getWindowWidth() / 2-20, gameManager->getWindowHeight() / 2+15), 100, 100, Resources::ScoreS);
		
		
	}

	else if (actualScore >= 60 * maxScore / 100 && actualScore < 80 * maxScore / 100) {
		perico->forceAnimationChange(Resources::PericoDab);
		letter = new EmptyObject(g, Vector2D(gameManager->getWindowWidth() / 2 - 20, gameManager->getWindowHeight() / 2 + 15), 100, 100, Resources::ScoreA);
	}

	else if (actualScore>=40*maxScore/100 && actualScore<60*maxScore/100) {
		perico->forceAnimationChange(Resources::PericoDab);
		letter = new EmptyObject(g, Vector2D(gameManager->getWindowWidth() / 2 - 20, gameManager->getWindowHeight() / 2 + 15), 100, 100, Resources::ScoreB);
	}

	else if (actualScore>=20*maxScore/100 && actualScore<40*maxScore/100) {
		perico->forceAnimationChange(Resources::PericoDab);
		letter = new EmptyObject(g, Vector2D(gameManager->getWindowWidth() / 2 - 20, gameManager->getWindowHeight() / 2 + 15), 100, 100, Resources::ScoreC);
	}

	else {
		perico->forceAnimationChange(Resources::PericoDab);
		letter = new EmptyObject(g, Vector2D(gameManager->getWindowWidth() / 2-20, gameManager->getWindowHeight() / 2+15), 100, 100, Resources::ScoreD);
		
		
	}

	stage.push_back(letter);
	stage.push_back(perico);
	
	
}

EndState::~EndState()
{
}

void EndState::backToMenu(GameManager * gameManager)
{
	gameManager->getMachine()->pushState(new MapState(gameManager));
}
void EndState::exit_(GameManager* gameManager) {
	gameManager->exit_ = true;
}
void EndState::render(Uint32 time, bool beatHandler){
	
	
	for (int i = 0; i < 2; i++) {
		buttons[i].first.render(time, beatHandler);
	}
	renderLetters(time, beatHandler);
	GameState::render(time);
}


bool EndState::handleEvent(Uint32 time, SDL_Event e)
{
	bool change = false;
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || e.key.keysym.sym == SDLK_DOWN) {
			nextButton();
			change = true;
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || e.key.keysym.sym == SDLK_UP) {
			backButton();
			change = true;
		}
		else if (buttons[0].second == true && buttons[1].second == false && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN)) {
			backToMenu(gameManager);
			change = true;
		}
		else if (buttons[0].second == false && buttons[1].second == true && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN)) {
			exit_(gameManager);
			change = true;
		}
		return change;
	
}


void EndState::nextButton()
{
	
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
	buttons[index].second = true;
	
}

void EndState::backButton()
{
	buttons[index].first.scale(0.5);
	buttons[index].second = false;
	if (index > min)
	{
		index--;
	}
	else {
		index = max;
	}
	buttons[index].first.scale(2);
	buttons[index].second = true;
}
void EndState::renderLetters(Uint32 time, bool beatHandler)
{

	Texture msg0(gameManager->getRenderer(),
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
	msg2.render(gameManager->getRenderer(), dest2);
	
}
