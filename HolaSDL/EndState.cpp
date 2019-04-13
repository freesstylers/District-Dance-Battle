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
	Character* letter;
	/*int width =
	int height = game->getWindowHeight();*/
	/*EmptyObject* cont = new EmptyObject(g, Vector2D(g->getWindowWidth() / 2 - 50, g->getWindowHeight() / 2 - 30),100,100,Resources::YButton);
	EmptyObject* sal = new EmptyObject(g, Vector2D(g->getWindowWidth() / 2 - 50, g->getWindowHeight() / 2 - 30), 100, 100, Resources::YButton);*/
	Character* perico = new Character(g, 150, 275, Vector2D(gameManager->getWindowWidth()/2-30,gameManager->getWindowHeight()/4-130), Resources::PericoDab);
	buttons[0].first=EmptyObject(g,Vector2D(g->getWindowWidth() / 2 , g->getWindowHeight() / 4*3 ), 50, 50, Resources::YButton);
	buttons[1].first=EmptyObject(g, Vector2D(g->getWindowWidth() / 2, g->getWindowHeight()/4 *3.5), 50, 50, Resources::YButton);
	buttons[0].second = true;
	buttons[1].second = false;
	buttons[0].first.scale(2);
	
	
	
	if (actualScore >= scoreLimit) {
		perico->forceAnimationChange(Resources::PericoDab);
		letter = new Character(g, 100, 100, Vector2D(gameManager->getWindowWidth()/2, gameManager->getWindowHeight()/2), Resources::ScoreS);
		
		
	}
	else {
		perico->forceAnimationChange(Resources::PericoDab);
		letter = new Character(g, 100, 100, Vector2D(gameManager->getWindowWidth() / 2, gameManager->getWindowHeight() / 2), Resources::ScoreS);
		
		//Resources::ScoreA;
	}
	/*stage.push_back(cont);
	stage.push_back(sal);*/
	/*firstButton = stage.begin();
	selectedButton = firstButton;
	(*selectedButton)->scale(2);*/
	stage.push_back(perico);
	stage.push_back(letter);
	
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
/*void EndState::update(Uint32 time) {
	for (int i = 0;i < 2;i++) {
		buttons[i];
		selectedButtons[i];
	}
	index;
}*/

bool EndState::handleEvent(Uint32 time, SDL_Event e)
{
	bool change = false;
	//if (SDL_CONTROLLERBUTTONDOWN) {
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
	//}
	//return GameState::handleEvent(time, e);
}

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
}*/

void EndState::nextButton()
{
	/*(*selectedButton)->scale(0.5);
	if ((*selectedButton) != stage.back()) {
		selectedButton++;
	}
	(*selectedButton)->scale(2);*/
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
	/*(*selectedButton)->scale(0.5);
	if (selectedButton != firstButton) {
		selectedButton--;
	}
	(*selectedButton)->scale(2);*/
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
	//dest.x = fondo_.getPosition().getX() + 5;
	dest.x = gameManager->getWindowWidth() / 4-150;
	dest.y = gameManager->getWindowHeight() / 4-100;
	dest.w = (gameManager->getWindowWidth() / 4);
	dest.h = gameManager->getWindowHeight() / 20;
	msg0.render(gameManager->getRenderer(), dest);

	Texture msg1(gameManager->getRenderer(),
			puntos ,*(gameManager->getServiceLocator()->getFonts()->getFont(
				Resources::PIXEL10)), { COLOR(0x00000000) });
	SDL_Rect dest1;
	//dest.x = fondo_.getPosition().getX() + 5;
	dest1.x = gameManager->getWindowWidth() / 2-150 ;
	dest1.y = gameManager->getWindowHeight() / 2 ;
	dest1.w = (gameManager->getWindowWidth() / 4);
	dest1.h = gameManager->getWindowHeight() / 20;
	msg1.render(gameManager->getRenderer(), dest1);

	Texture msg2(gameManager->getRenderer(),
		val, *(gameManager->getServiceLocator()->getFonts()->getFont(
			Resources::PIXEL10)), { COLOR(0x00000000) });
	SDL_Rect dest2;
	//dest.x = fondo_.getPosition().getX() + 5;
	dest2.x = gameManager->getWindowWidth() / 2 - 150;
	dest2.y = gameManager->getWindowHeight() / 2 +50;
	dest2.w = (gameManager->getWindowWidth() / 4);
	dest2.h = gameManager->getWindowHeight() / 20;
	msg2.render(gameManager->getRenderer(), dest2);
}
