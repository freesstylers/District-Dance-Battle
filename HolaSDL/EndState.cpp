#include "EndState.h"

/*EndState::EndState() {
	for (int i = 0;i < 2;i++) {
		buttons[i] = EmptyObject();
	}
	selectedButtons[0] = true;
	selectedButtons[1] = false;
}*/

EndState::EndState(GameManager* g, int prevMaxScoreE, int prevMaxScoreH, int* califs1, int actualScore, int maxScore, int percentage, int lvl, bool isSingleplayer, bool hardMode, int actualScore2, int* califs2) : GameState(g)
{
	level = lvl;
	punt = maxScore;
	controller = SDL_GameControllerOpen(0);
	gameManager = g;
	int scoreLimit = (percentage * maxScore)/ 100;
	if (actualScore >= scoreLimit)
		passed = true;
	else
		passed = false;


	points = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO50), Vector2D(gameManager->getDefaultWindowWidth() / 2, 50));
	points->setText("Puntuación final: " + makeScoreBetter(actualScore), SDL_Color{ (0), (0), (0), (255) });
	points->setPosition(Vector2D(gameManager->getDefaultWindowWidth() / 2, 50) - Vector2D(points->getWidth() / 2, 0));

	tooltip = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));
	tooltip->setText("Pulsa A para salir", SDL_Color{ (0), (0), (0), (255) });
	tooltip->setPosition(Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight()) - Vector2D(tooltip->getWidth() / 2, tooltip->getHeight() + 10));


	EmptyObject* letter = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 + 325, gameManager->getDefaultWindowHeight() / 2 - 40), 160, 260, Resources::ScoreS);

	Character* perico = new Character(g, 300, 540, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 500, 160), Resources::PericoDab);
	perico->isAnimationSynced(false);
	perico->setAnimationFramerate(4);
	
	if (actualScore >= 90 * maxScore/100) {
		perico->forceAnimationChange(Resources::PericoMaxPower);
		letter->forceAnimationChange(Resources::ScoreS);
	}

	else if (actualScore >= 70 * maxScore / 100) {
		perico->forceAnimationChange(Resources::PericoDance1);
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

	if (isSingleplayer)
	{
		stage.push_back(new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::EndBG));
		stage.push_back(letter);
		stage.push_back(perico);

		highScoreText = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 130, 200));
		highScoreText->setText("Mejor puntuación", SDL_Color{ (0), (0), (0), (255) });


		if (hardMode)
		{
			highScore = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 230 - to_string(prevMaxScoreH).length(), 250));
			highScore->setText(to_string(prevMaxScoreH), SDL_Color{ (0), (0), (0), (255) });
		}
		else
		{
			highScore = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 230 - to_string(prevMaxScoreE).length(), 250));
			highScore->setText(to_string(prevMaxScoreE), SDL_Color{ (0), (0), (0), (255) });
		}

		EmptyObject* Wow = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight() / 2 - 40), 64, 64, Resources::FeedbackPerfect);
		stage.push_back(Wow);
		EmptyObject* Good = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight() / 2 + 30), 64, 64, Resources::FeedbackGood);
		stage.push_back(Good);
		EmptyObject* Ok = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight() / 2 + 100), 64, 64, Resources::FeedbackRegular);
		stage.push_back(Ok);
		EmptyObject* Bad = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight() / 2 + 170), 64, 64, Resources::FeedbackBad);
		stage.push_back(Bad);


		Wow1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Wow->getPosition().getX() - 45 - to_string(califs1[0]).length() * 10, Wow->getPosition().getY() + 15));
		Wow1->setText(to_string(califs1[0]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Wow1);

		Good1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Good->getPosition().getX() - 45 - to_string(califs1[1]).length() * 10, Good->getPosition().getY() + 15));
		Good1->setText(to_string(califs1[1]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Good1);

		Ok1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Ok->getPosition().getX() - 45 - to_string(califs1[2]).length() * 10, Ok->getPosition().getY() + 15));
		Ok1->setText(to_string(califs1[2]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Ok1);

		Bad1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Bad->getPosition().getX() - 45 - to_string(califs1[3]).length() * 10, Bad->getPosition().getY() + 15));
		Bad1->setText(to_string(califs1[3]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Bad1);

		points2 = nullptr;
	}
	else
	{
		highScoreText = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 130, 215));
		highScoreText->setText("Mejor puntuación", SDL_Color{ (0), (0), (0), (255) });


		if (hardMode)
		{
			highScore = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 230 - to_string(prevMaxScoreH).length(), 265));
			highScore->setText(to_string(prevMaxScoreH), SDL_Color{ (0), (0), (0), (255) });
		}
		else
		{
			highScore = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 230 - to_string(prevMaxScoreE).length(), 265));
			highScore->setText(to_string(prevMaxScoreE), SDL_Color{ (0), (0), (0), (255) });
		}

		stage.push_back(new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::EndBG2));
		letter->setPosition(letter->getPosition() + Vector2D(60, 0));
		letter->scale(0.7);
		stage.push_back(letter);
		perico->setPosition(Vector2D(gameManager->getDefaultWindowWidth() / 2 - 400, 180));
		perico->scale(0.7);
		stage.push_back(perico);

		EmptyObject* letter2 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 325 - 55 - 160, gameManager->getDefaultWindowHeight() / 2 - 40), 160, 260, Resources::ScoreS);
		letter2->scale(0.7);

		Character* perico2 = new Character(g, 300, 540, Vector2D(gameManager->getDefaultWindowWidth() / 2 + 65, 180), Resources::PericoDab);
		perico2->scale(0.7);
		perico2->isAnimationSynced(false);
		perico2->setAnimationFramerate(4);

		EmptyObject* Wow = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 37, gameManager->getDefaultWindowHeight() / 2 - 40), 64, 64, Resources::FeedbackPerfect);
		stage.push_back(Wow);
		EmptyObject* Good = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 37, gameManager->getDefaultWindowHeight() / 2 + 30), 64, 64, Resources::FeedbackGood);
		stage.push_back(Good);
		EmptyObject* Ok = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 36, gameManager->getDefaultWindowHeight() / 2  + 100), 64, 64, Resources::FeedbackRegular);
		stage.push_back(Ok);
		EmptyObject* Bad = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 38, gameManager->getDefaultWindowHeight() / 2 + 170), 64, 64, Resources::FeedbackBad);
		stage.push_back(Bad);

		
		Wow1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Wow->getPosition().getX() - 25 - to_string(califs1[0]).length() * 10, Wow->getPosition().getY() + 15));
		Wow1->setText(to_string(califs1[0]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Wow1);

		Good1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Good->getPosition().getX() - 25 - to_string(califs1[1]).length() * 10, Good->getPosition().getY() + 15));
		Good1->setText(to_string(califs1[1]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Good1);

		Ok1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Ok->getPosition().getX() - 25 - to_string(califs1[2]).length() * 10, Ok->getPosition().getY() + 15));
		Ok1->setText(to_string(califs1[2]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Ok1);

		Bad1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Bad->getPosition().getX() - 25 - to_string(califs1[3]).length() * 10, Bad->getPosition().getY() + 15));
		Bad1->setText(to_string(califs1[3]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Bad1);

		TextObject* Wow2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Wow->getPosition().getX() + 70 + to_string(califs2[0]).length() * 10, Wow->getPosition().getY() + 15));
		Wow2->setText(to_string(califs2[0]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Wow2);

		TextObject* Good2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Good->getPosition().getX() + 70 + to_string(califs2[1]).length() * 10, Good->getPosition().getY() + 15));
		Good2->setText(to_string(califs2[1]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Good2);

		TextObject* Ok2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Ok->getPosition().getX() + 70 + to_string(califs2[2]).length() * 10, Ok->getPosition().getY() + 15));
		Ok2->setText(to_string(califs2[2]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Ok2);

		TextObject* Bad2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Bad->getPosition().getX() + 70 + to_string(califs2[3]).length() * 10, Bad->getPosition().getY() + 15));
		Bad2->setText(to_string(califs2[3]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Bad2);




		if (actualScore >= 90 * maxScore / 100) {
			perico2->forceAnimationChange(Resources::PericoMaxPower);
			letter2->forceAnimationChange(Resources::ScoreS);
		}

		else if (actualScore >= 70 * maxScore / 100) {
			perico2->forceAnimationChange(Resources::PericoDance1);
			letter2->forceAnimationChange(Resources::ScoreA);
		}

		else if (actualScore >= 50 * maxScore / 100) {
			perico2->forceAnimationChange(Resources::PericoDance1);
			letter2->forceAnimationChange(Resources::ScoreB);
		}

		else if (actualScore >= 30 * maxScore / 100) {
			perico2->forceAnimationChange(Resources::PericoDab);
			letter2->forceAnimationChange(Resources::ScoreC);
		}

		else {
			perico2->forceAnimationChange(Resources::PericoIdle);
			letter2->forceAnimationChange(Resources::ScoreD);
		}


		if (actualScore2 >= 90 * maxScore / 100) {
			perico->forceAnimationChange(Resources::PericoMaxPower);
			letter->forceAnimationChange(Resources::ScoreS);
		}

		else if (actualScore2 >= 70 * maxScore / 100) {
			perico->forceAnimationChange(Resources::PericoDance1);
			letter->forceAnimationChange(Resources::ScoreA);
		}

		else if (actualScore2 >= 50 * maxScore / 100) {
			perico->forceAnimationChange(Resources::PericoDance1);
			letter->forceAnimationChange(Resources::ScoreB);
		}

		else if (actualScore2 >= 30 * maxScore / 100) {
			perico->forceAnimationChange(Resources::PericoDab);
			letter->forceAnimationChange(Resources::ScoreC);
		}

		else {
			perico->forceAnimationChange(Resources::PericoIdle);
			letter->forceAnimationChange(Resources::ScoreD);
		}

		stage.push_back(letter2);
		stage.push_back(perico2);


		points->setText("P1: " + makeScoreBetter(actualScore), SDL_Color{ (0), (0), (0), (255) });
		points->setPosition(Vector2D(gameManager->getDefaultWindowWidth() / 5, 50) - Vector2D(points->getWidth() / 2, 0));

		points2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO50), Vector2D(gameManager->getDefaultWindowWidth() / 4, 50));
		points2->setText("P2: " + makeScoreBetter(actualScore2), SDL_Color{ (0), (0), (0), (255) });
		points2->setPosition(Vector2D(gameManager->getDefaultWindowWidth() * 4 / 5, 50) - Vector2D(points2->getWidth() / 2, 0));
	}

	if (!isSingleplayer)
	{
		if (actualScore2 > actualScore)
			actualScore = actualScore2;
	}

	if (hardMode)
	{
		if (actualScore > prevMaxScoreH)
			saveScore(prevMaxScoreE, actualScore);
	}
	else
	{
		if (actualScore > prevMaxScoreE)
			saveScore(actualScore, prevMaxScoreH);
	}
}

EndState::~EndState()
{
	delete points;
	delete points2;
	delete tooltip;
}

void EndState::backToMenu(GameManager * gameManager)
{
	gameManager->getMachine()->changeState(new MapState(gameManager));
	gameManager->getServiceLocator()->getAudios()->haltChannel(0);
}

void EndState::render(Uint32 time, bool beatHandler)
{
	GameState::render(time);
	tooltip->render(time);
	points->render(time);
	highScoreText->render(time);
	highScore->render(time);

	if (points2 != nullptr)
		points2->render(time);
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
string EndState::makeScoreBetter(int score)
{
	string ret = "";

	for (int i = punt; i > 1; i)
	{
		if (score < i) {
			ret += "0";
			i = i / 10;
		}
		else
			break;
	}

	ret += to_string(score);

	return ret;
}
void EndState::renderLetters(Uint32 time, bool beatHandler)
{

	/*Texture msg0(gameManager->getRenderer(),
		types[level],
		*(gameManager->getServiceLocator()->getFonts()->getFont(
			Resources::RETRO20)), { COLOR(0x00000000) });
	SDL_Rect dest;
	dest.x = gameManager->getDefaultWindowWidth() / 4-150;
	dest.y = gameManager->getDefaultWindowHeight() / 4-100;
	dest.w = (gameManager->getDefaultWindowWidth() / 4);
	dest.h = gameManager->getDefaultWindowHeight() / 20;
	msg0.render(gameManager->getRenderer(), dest);

	Texture msg1(gameManager->getRenderer(),
			puntos + to_string(punt) ,*(gameManager->getServiceLocator()->getFonts()->getFont(
				Resources::RETRO10)), { COLOR(0x00000000) });
	SDL_Rect dest1;
	dest1.x = gameManager->getDefaultWindowWidth() / 2-150 ;
	dest1.y = gameManager->getDefaultWindowHeight() / 2 ;
	dest1.w = (gameManager->getDefaultWindowWidth() / 4);
	dest1.h = gameManager->getDefaultWindowHeight() / 20;
	msg1.render(gameManager->getRenderer(), dest1);

	Texture msg2(gameManager->getRenderer(),
		val, *(gameManager->getServiceLocator()->getFonts()->getFont(
			Resources::RETRO10)), { COLOR(0x00000000) });
	SDL_Rect dest2;
	dest2.x = gameManager->getDefaultWindowWidth() / 2 - 150;
	dest2.y = gameManager->getDefaultWindowHeight() / 2 +50;
	dest2.w = (gameManager->getDefaultWindowWidth() / 4);
	dest2.h = gameManager->getDefaultWindowHeight() / 20;
	msg2.render(gameManager->getRenderer(), dest2);*/
	
}

void EndState::saveScore(int scoreE, int scoreH)
{
	string filename = "resources/data/" + to_string(level) + ".txt";

	ofstream archivo(filename);

	

	archivo << 0 << " " << scoreE << endl;
	archivo << 1 << " " << scoreH << endl;

	archivo.close();
}
