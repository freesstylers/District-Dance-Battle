#include "TutorialState.h"
#include "GameManager.h"



TutorialState::TutorialState(GameManager* g) : PlayState(g, 9, true, false)
{
	tutorialBox = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 - 60, g->getDefaultWindowHeight() / 2 - 30), 64, 64, Resources::MetroOn);
	tutorialBox->setActive(false);

	stage.push_back(tutorialBox);

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
			resumeTutorial(SDL_GetTicks() - auxTime);
		}
	}

	return true;
}

bool TutorialState::pauseTutorial()
{
	if (!isPaused && !isTutorialPaused)
	{
		manager->getServiceLocator()->getAudios()->pauseChannel(0);
		isPaused = true;
		isTutorialPaused = true;
		tutorialBox->setActive(true);

		auxTime = SDL_GetTicks();
	}

	return isPaused;
}

void TutorialState::resumeTutorial(unsigned int timePaused)
{
	if (isPaused && isTutorialPaused)
	{
		manager->getServiceLocator()->getAudios()->resumeChanne(0);
		isPaused = false;
		isTutorialPaused = false;

		tutorialBoxAnim++;
		tutorialBox->forceAnimationChange(tutorialBoxAnim);


		tutorialBox->setActive(false);

		timer->setOffset(timePaused);
		minigameController->Reset();
	}
}
