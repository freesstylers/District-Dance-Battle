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


	letter = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 + 325, gameManager->getDefaultWindowHeight() / 2 - 40), 160, 260, Resources::ScoreS);

	perico = new Character(g, 300, 540, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 500, 160), Resources::PericoDab);
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
		highScoreText = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 130, 205));
		highScoreText->setText("Mejor puntuación", SDL_Color{ (0), (0), (0), (255) });


		if (hardMode)
		{
			highScore = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 230, 250));
			highScore->setText(to_string(prevMaxScoreH), SDL_Color{ (0), (0), (0), (255) });
		}
		else
		{
			highScore = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 230, 250));
			highScore->setText(to_string(prevMaxScoreE), SDL_Color{ (0), (0), (0), (255) });
		}

		highScore->setPosition(Vector2D(gameManager->getDefaultWindowWidth() / 2, 280) - Vector2D(highScore->getWidth() / 2, highScore->getHeight()));

		EndBG = new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::EndBG);

		stage.push_back(EndBG);
		stage.push_back(letter);
		stage.push_back(perico);

		Wow = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight() / 2 - 40), 64, 64, Resources::FeedbackPerfect);
		stage.push_back(Wow);
		Good = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight() / 2 + 30), 64, 64, Resources::FeedbackGood);
		stage.push_back(Good);
		Ok = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight() / 2 + 100), 64, 64, Resources::FeedbackRegular);
		stage.push_back(Ok);
		Bad = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2, gameManager->getDefaultWindowHeight() / 2 + 170), 64, 64, Resources::FeedbackBad);
		stage.push_back(Bad);


		Wow1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Wow->getPosition().getX() - 45 - to_string(califs1[3]).length() * 10, Wow->getPosition().getY() + 15));
		Wow1->setText(to_string(califs1[3]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Wow1);

		Good1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Good->getPosition().getX() - 45 - to_string(califs1[2]).length() * 10, Good->getPosition().getY() + 15));
		Good1->setText(to_string(califs1[2]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Good1);

		Ok1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Ok->getPosition().getX() - 45 - to_string(califs1[1]).length() * 10, Ok->getPosition().getY() + 15));
		Ok1->setText(to_string(califs1[1]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Ok1);

		Bad1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Bad->getPosition().getX() - 45 - to_string(califs1[0]).length() * 10, Bad->getPosition().getY() + 15));
		Bad1->setText(to_string(califs1[0]), SDL_Color{ (0), (0), (0), (255) });
		stage.push_back(Bad1);

		points2 = nullptr;
	}
	else
	{

		highScoreText = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 130, 210));
		highScoreText->setText("Mejor puntuación", SDL_Color{ (0), (0), (0), (255) });


		if (hardMode)
		{
			highScore = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 230, 280));
			highScore->setText(to_string(prevMaxScoreH), SDL_Color{ (0), (0), (0), (255) });
		}
		else
		{
			highScore = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(gameManager->getDefaultWindowHeight() / 2 + 230, 280));
			highScore->setText(to_string(prevMaxScoreE), SDL_Color{ (0), (0), (0), (255) });
		}

		highScore->setPosition(Vector2D(gameManager->getDefaultWindowWidth() / 2, 300) - Vector2D(highScore->getWidth() / 2, highScore->getHeight()));

		EndBG = new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::EndBG2);
		stage.push_back(EndBG);

		letter->setPosition(letter->getPosition() + Vector2D(60, 0));
		letter->scale(0.7);
		stage.push_back(letter);
		perico->setPosition(Vector2D(gameManager->getDefaultWindowWidth() / 2 - 400, 180));
		perico->scale(0.7);
		stage.push_back(perico);

		letter2 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 325 - 55 - 160, gameManager->getDefaultWindowHeight() / 2 - 40), 160, 260, Resources::ScoreS);
		letter2->scale(0.7);

		perico2 = new Character(g, 300, 540, Vector2D(gameManager->getDefaultWindowWidth() / 2 + 65, 180), Resources::PericoDab);
		perico2->scale(0.7);
		perico2->isAnimationSynced(false);
		perico2->setAnimationFramerate(4);

		Wow = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 32, gameManager->getDefaultWindowHeight() / 2 - 40), 64, 64, Resources::FeedbackPerfect);
		stage.push_back(Wow);
		Good = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 32, gameManager->getDefaultWindowHeight() / 2 + 30), 64, 64, Resources::FeedbackGood);
		stage.push_back(Good);
		Ok = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 32, gameManager->getDefaultWindowHeight() / 2  + 100), 64, 64, Resources::FeedbackRegular);
		stage.push_back(Ok);
		Bad = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 - 32, gameManager->getDefaultWindowHeight() / 2 + 170), 64, 64, Resources::FeedbackBad);
		stage.push_back(Bad);

		
		Wow1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Wow->getPosition().getX() - 25, Wow->getPosition().getY() - 5));
		Wow1->setText(to_string(califs1[3]), SDL_Color{ (0), (0), (0), (255) });
		Wow1->setPosition(Wow1->getPosition() - Vector2D(Wow1->getWidth() / 2, - Wow1->getHeight() / 2));
		stage.push_back(Wow1);

		Good1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Good->getPosition().getX() - 25, Good->getPosition().getY() - 5));
		Good1->setText(to_string(califs1[2]), SDL_Color{ (0), (0), (0), (255) });
		Good1->setPosition(Good1->getPosition() - Vector2D(Good1->getWidth() / 2, - Good1->getHeight() / 2));
		stage.push_back(Good1);

		Ok1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Ok->getPosition().getX() - 25, Ok->getPosition().getY() - 5));
		Ok1->setText(to_string(califs1[1]), SDL_Color{ (0), (0), (0), (255) });
		Ok1->setPosition(Ok1->getPosition() - Vector2D(Ok1->getWidth() / 2, - Ok1->getHeight() / 2));
		stage.push_back(Ok1);

		Bad1 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Bad->getPosition().getX() - 25, Bad->getPosition().getY() - 5));
		Bad1->setText(to_string(califs1[0]), SDL_Color{ (0), (0), (0), (255) });
		Bad1->setPosition(Bad1->getPosition() - Vector2D(Bad1->getWidth() / 2, - Bad1->getHeight() / 2));
		stage.push_back(Bad1);

		Wow2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Wow->getPosition().getX() + 89, Wow->getPosition().getY() - 5));
		Wow2->setText(to_string(califs2[3]), SDL_Color{ (0), (0), (0), (255) });
		Wow2->setPosition(Wow2->getPosition() - Vector2D(Wow2->getWidth() / 2, - Wow2->getHeight() / 2));
		stage.push_back(Wow2);

		Good2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Good->getPosition().getX() + 89, Good->getPosition().getY() - 5));
		Good2->setText(to_string(califs2[2]), SDL_Color{ (0), (0), (0), (255) });
		Good2->setPosition(Good2->getPosition() - Vector2D(Good2->getWidth() / 2, - Good2->getHeight() / 2));
		stage.push_back(Good2);

		Ok2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Ok->getPosition().getX() + 89, Ok->getPosition().getY() - 5));
		Ok2->setText(to_string(califs2[1]), SDL_Color{ (0), (0), (0), (255) });
		Ok2->setPosition(Ok2->getPosition() - Vector2D(Ok2->getWidth() / 2, - Ok2->getHeight() / 2));
		stage.push_back(Ok2);

		Bad2 = new TextObject(g, g->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(Bad->getPosition().getX() + 89, Bad->getPosition().getY() - 5));
		Bad2->setText(to_string(califs2[0]), SDL_Color{ (0), (0), (0), (255) });
		Bad2->setPosition(Bad2->getPosition() - Vector2D(Bad2->getWidth() / 2, - Bad2->getHeight() / 2));
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
	delete highScoreText;
	delete highScore;
	delete Wow1;
	delete Good1;
	delete Ok1;
	delete Bad1;
	delete Wow2;
	delete Good2;
	delete Ok2;
	delete Bad2;

	delete Wow;
	delete Good;
	delete Ok;
	delete Bad;
	delete letter;
	delete letter2;

	delete perico;
	delete perico2;
	delete EndBG;

	stage.clear();
	

	points = nullptr;
	points2 = nullptr;
	tooltip = nullptr;
	highScoreText = nullptr;
	highScore = nullptr;
	Wow1 = nullptr;
	Good1 = nullptr;
	Ok1 = nullptr;
	Bad1 = nullptr;
	Wow2 = nullptr;
	Good2 = nullptr;
	Ok2 = nullptr;
	Bad2 = nullptr;
	Wow = nullptr;
	Good = nullptr;
	Ok = nullptr;
	Bad = nullptr;
	perico = nullptr;
	letter = nullptr;
}

void EndState::backToMenu(GameManager * gameManager)
{
	gameManager->getServiceLocator()->getAudios()->haltChannel(0);
	gameManager->getMachine()->pushState(new MapState(gameManager));
}

void EndState::backToMenuWin(GameManager * gameManager)
{
	gameManager->getServiceLocator()->getAudios()->haltChannel(0);
	gameManager->getMachine()->pushState(new DialogState(gameManager, (level * 2 + 6), 0, true, false, 0, 0));
}

void EndState::backToMenuLose(GameManager * gameManager)
{
	gameManager->getServiceLocator()->getAudios()->haltChannel(0);
	gameManager->getMachine()->pushState(new DialogState(gameManager, (level*2 + 7), 0, true, false, 0, 0));
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
			if (level <= 5) {
				if (passed)
					backToMenuWin(gameManager);
				else
					backToMenuLose(gameManager);
			}
			else {
				backToMenu(gameManager);
			}
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
	string filename = "resources/data/" + to_string(level) + ".ddb";

	ofstream archivo(filename);

	

	archivo << 0 << " " << scoreE << endl;
	archivo << 1 << " " << scoreH << endl;

	archivo.close();
}
