#include "TutorialState.h"
#include "GameManager.h"



TutorialState::TutorialState(GameManager* g) : PlayState(g, 0, true, false)
{
	tutorialBox = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 +145 , g->getDefaultWindowHeight() / 2 - 80), 612*0.75, 252*0.75, Resources::TutoBox1);
	tutorialBox->setActive(false);

	tutoFiltro= new EmptyObject(g, Vector2D(0, 0), g->getDefaultWindowWidth(), g->getDefaultWindowHeight(), Resources::TutoFiltro);
	tutoFiltro->setActive(false);

	//first stop
	note1 = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 + 57, g->getDefaultWindowHeight() / 2 - 32), 70, 70, Resources::YButton);
	note2 = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 + 57, g->getDefaultWindowHeight() / 2 - 290), 70, 70, Resources::XButton);
	note3 = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 - 123, 206), 70, 70, Resources::YButton);
	circle1 = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 - 119 - 55 / 2, 565), 100, 100, Resources::Point);
	circle2 = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 + 57 - 45 / 2, 565), 100, 100, Resources::Point);

	note1->setActive(false);
	note2->setActive(false);
	note3->setActive(false);
	circle1->setActive(false);
	circle2->setActive(false);

	//second stop
	barraPuntos = new EmptyObject(g, Vector2D(6, 600 - 402), 82, 402, Resources::StarBar);

	barraPuntos->setActive(false);

	//third stop
	barraAmarilla = new EmptyObject(g, Vector2D(50, 35), 600, 14, Resources::YellowBar);
	nota = new EmptyObject(g, Vector2D(600 + 50 - 13, 32), 18, 22, Resources::NoteIcon);

	barraAmarilla->setActive(false);
	nota->setActive(false);

	//fourth stop
	bomba= new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 + 57, g->getDefaultWindowHeight() / 2 - 205), 70, 70, Resources::FlechaEspBomba);
	bomba->setActive(false);

	stage.push_back(tutoFiltro);
	stage.push_back(tutorialBox);
	stage.push_back(note1);
	stage.push_back(note2);
	stage.push_back(note3);
	stage.push_back(circle1);
	stage.push_back(circle2);
	stage.push_back(barraPuntos);
	stage.push_back(barraAmarilla);
	stage.push_back(nota);
	stage.push_back(bomba);

	controller = SDL_GameControllerOpen(0);
}


TutorialState::~TutorialState()
{
}

void TutorialState::restart()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->pushState(new TutorialState(manager));
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
		if (extraTimer->DeltaTime() < level->songLength / pauseAmount)
		{
			extraTimer->Update();

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

		switch (numStops)
		{
		case 0:
			note1->setActive(true);
			note2->setActive(true);
			note3->setActive(true);
			circle1->setActive(true);
			circle2->setActive(true);
			break;
		case 1:
			barraPuntos->setActive(true);
			break;
		case 2:
			barraAmarilla->setActive(true);
			nota->setActive(true);
			break;
		case 3:
			bomba->setActive(true);
			break;
		}

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
		case 0:
			tutorialBoxAnim = Resources::TutoBox1;
			
			break;
		case 1:
			tutorialBoxAnim = Resources::TutoBox2;
			tutorialBox->setPosition(Vector2D(120, g->getDefaultWindowHeight() / 2 - 30));
			note1->setActive(false);
			note2->setActive(false);
			note3->setActive(false);
			circle1->setActive(false);
			circle2->setActive(false);

			
			break;
		case 2:
			tutorialBoxAnim = Resources::TutoBox3;
			tutorialBox->setPosition(Vector2D(g->getDefaultWindowWidth() / 2 - (612 * 0.75)/2, 100));

			barraPuntos->setActive(false);
			break;
		case 3:
			tutorialBoxAnim = Resources::TutoBox4;
			tutorialBox->setPosition(Vector2D(g->getDefaultWindowWidth() / 2 + 145, g->getDefaultWindowHeight() / 2 - 80));

			barraAmarilla->setActive(false);
			nota->setActive(false);
			break;
		case 4:
			tutorialBoxAnim = Resources::TutoBox5;
			tutorialBox->setPosition(Vector2D(g->getDefaultWindowWidth() / 2 - (612 * 0.75) / 2, g->getDefaultWindowHeight() / 2 - 100));

			bomba->setActive(false);
			break;
		}

		tutorialBox->forceAnimationChange(tutorialBoxAnim);

		tutoFiltro->setActive(false);
		tutorialBox->setActive(false);

		timer->setOffset(timePaused);
		extraTimer->Reset();
	}
}
