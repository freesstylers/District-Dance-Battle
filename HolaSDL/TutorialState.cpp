#include "TutorialState.h"
#include "GameManager.h"



TutorialState::TutorialState(GameManager* g) : PlayState(g, 0, true, false)
{
	tutorialBox = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 +145 , g->getDefaultWindowHeight() / 2 - 80), 612*0.75, 252*0.75, Resources::TutoBox1);
	tutorialBox->setActive(false);

	tutoFiltro= new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::TutoFiltro);
	tutoFiltro->setActive(false);

	//first stop
	note1 = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 + 145, g->getDefaultWindowHeight() / 2 - 80), 70, 70, Resources::YButton);
	note2 = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 + 145, 400), 70, 70, Resources::YButton);
	note3 = new EmptyObject(g, Vector2D(500, 200), 70, 70, Resources::YButton);

	note1->setActive(false);
	note2->setActive(false);
	note3->setActive(false);
	//second stop

	//third stop

	//fourth stop

	stage.push_back(tutoFiltro);
	stage.push_back(tutorialBox);
	stage.push_back(note1);
	stage.push_back(note2);
	stage.push_back(note3);

	controller = SDL_GameControllerOpen(0);
}


TutorialState::~TutorialState()
{
}

void TutorialState::update(Uint32 time)
{
	if (!isPaused) {

		GameState::update(time);
		if (!isSingleplayer)
		{
			if (player1->currentScore > player2->currentScore && player1->currentScore != 0)
			{
				player1->getleftBar()->forceAnimationChange(Resources::Recuadro1PWin);
				player1->getrightBar()->forceAnimationChange(Resources::Recuadro1PWin);
				player2->getleftBar()->forceAnimationChange(Resources::Recuadro2P);
				player2->getrightBar()->forceAnimationChange(Resources::Recuadro2P);
				crown->setPosition(Vector2D(player1->getleftBar()->getPosition().getX() + player1->getleftBar()->getWidth() / 2 + 6, player1->getleftBar()->getPosition().getY() - 60));
			}
			else if (player2->currentScore >= player1->currentScore && player2->currentScore != 0)
			{
				player2->getleftBar()->forceAnimationChange(Resources::Recuadro2PWin);
				player2->getrightBar()->forceAnimationChange(Resources::Recuadro2PWin);
				player1->getleftBar()->forceAnimationChange(Resources::Recuadro1P);
				player1->getrightBar()->forceAnimationChange(Resources::Recuadro1P);
				crown->setPosition(Vector2D(player2->getleftBar()->getPosition().getX() + player2->getleftBar()->getWidth() / 2 + 6, player2->getleftBar()->getPosition().getY() - 60));
			}
		}
		if (minigameController->DeltaTime() < level->songLength / pauseAmount)
		{
			minigameController->Update();

			if (levelArrows_.empty() && levelButtons_.empty()) {
				if (player1->screenArrows_.empty() && player1->screenButtons_.empty()) {
					if ((player2 == nullptr || (player2->screenArrows_.empty() && player2->screenButtons_.empty())))
					{
						if (songEndWaitTime == 0)
							songEndWaitTime = time;

						else if (time - songEndWaitTime >= 2000)
							songIsOver = true;
					}
				}
			}

			else {
				timer->Update();
				if (timer->DeltaTime() > (bh->getBeatTime() / 1000.0) - msDiff)
				{
					msDiff += timer->DeltaTime() - (bh->getBeatTime() / 1000.0);
					generateArrows();
					generateButtons();
					timer->Reset();

					beatSignal = true;
				}
			}
		}
		else {
			pauseTutorial();
		}
		if (timer->DeltaTime() > ((bh->getBeatTime() / 1000.0) / (animationFramesPerBeat / 1000)) - msDiff)
		{
			//aqui se divide el beatTime lo necesario para animar las frames especificadas entre cada beat

			beatSignal = true;
		}
		if (songIsOver)
			songOver();
	}
}

bool TutorialState::handleEvent(Uint32 time, SDL_Event e)
{
	PlayState::handleEvent(time, e);


	if (e.type == SDL_CONTROLLERBUTTONDOWN || e.type == SDL_KEYDOWN) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_SPACE) {
			resumeTutorial(manager,SDL_GetTicks() - auxTime);
		}
	}

	return true;
}


void TutorialState::exit()
{
	songOver();
}


bool TutorialState::pauseTutorial()
{
	if (!isPaused && !isTutorialPaused)
	{
		manager->getServiceLocator()->getAudios()->pauseChannel(0);
		isPaused = true;
		isTutorialPaused = true;

		tutoFiltro->setActive(true);
		tutorialBox->setActive(true);

		auxTime = SDL_GetTicks();
	}

	return isPaused;
}

void TutorialState::resumeTutorial(GameManager* g, unsigned int timePaused)
{
	if (isPaused && isTutorialPaused)
	{
		manager->getServiceLocator()->getAudios()->resumeChanne(0);
		isPaused = false;
		isTutorialPaused = false;

		numStops++;

		switch (numStops) {
		case 1:
			tutorialBoxAnim = Resources::TutoBox1;
			note1->setActive(true);
			note2->setActive(true);
			note3->setActive(true);
			break;
		case 2:
			tutorialBoxAnim = Resources::TutoBox2;
			tutorialBox->setPosition(Vector2D(120, g->getDefaultWindowHeight() / 2 - 30));
			break;
		case 3:
			tutorialBoxAnim = Resources::TutoBox3;
			tutorialBox->setPosition(Vector2D(g->getDefaultWindowWidth() / 2 - (612 * 0.75)/2, 100));
			break;
		case 4:
			tutorialBoxAnim = Resources::TutoBox4;
			tutorialBox->setPosition(Vector2D(g->getDefaultWindowWidth() / 2 + 145, g->getDefaultWindowHeight() / 2 - 80));
			break;
		}

		tutorialBox->forceAnimationChange(tutorialBoxAnim);
		//tutoFiltro->forceAnimationChange(Resources::TutoFiltro);

		tutoFiltro->setActive(false);
		//tutoFiltro->setAlpha(10);
		tutorialBox->setActive(false);

		timer->setOffset(timePaused);
		minigameController->Reset();
	}
}
