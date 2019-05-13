#include "LevelInputManager.h"
#include "PlayState.h"
#include "GameManager.h"
#include <string>
#include "PlayerPack.h"
#include "RedEffect.h"


LevelInputManager::LevelInputManager(PlayState* l, PlayerPack* pl, int numctrl)
{
	numctrl_ = numctrl;
	level = l;
	player = pl;
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(numctrl_);
	
}


LevelInputManager::~LevelInputManager()
{
}

bool LevelInputManager::handleInput(Uint32 time, const SDL_Event& event) {

	bool ret = false;

	if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup) {
		level->getGameManager()->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0, 1);
		//level->particles->generate();
	}
	if (event.type == SDL_CONTROLLERBUTTONUP)
	{
		keyup = true;
		keyup2 = true;
	}
	if ((blockpause < time - 500) && (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START)) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DELETE)) {
		ret = ret || level->pause();
		blockpause = 0;
	}
	if (!player->screenArrows_.empty())
	{
		auto it = player->screenArrows_.front();
		if (it != nullptr && abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 100)
		{
			if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup)
			{
				if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 10)
				{
					cout << "perfecto" << endl;
					player->feedbackLeft->addFeedback(Resources::FeedbackPerfect);
					player->hitLeft->addHit(Resources::HitGold, it->getPosition());
					player->updateScoreNote(1);
					player->addCombo(1);
					player->addCalifications(3);
					if (numFailed >= 1)
						numFailed -= 1;
				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 25)
				{
					cout << "bien" << endl;
					player->feedbackLeft->addFeedback(Resources::FeedbackGood);
					player->hitLeft->addHit(Resources::HitSilver, it->getPosition());
					player->updateScoreNote(2);
					player->addCombo(1);
					player->addCalifications(2);
					if (numFailed >= 2)
						numFailed -= 2;
					else
						numFailed = 0;

				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 50)
				{
					cout << "regular" << endl;
					player->feedbackLeft->addFeedback(Resources::FeedbackRegular);
					player->hitLeft->addHit(Resources::HitCopper, it->getPosition());
					player->updateScoreNote(3);
					player->addCombo(1);
					player->addCalifications(1);
					if (numFailed >= 3)
						numFailed -= 3;
					else
						numFailed = 0;

				}
				else
				{
					cout << "mala punteria" << endl;
					player->feedbackLeft->addFeedback(Resources::FeedbackBad);
					level->showError();
					player->errorLeft();
					player->resetCombo();
					player->addCalifications(0);
					numFailed++;

				}
				keyup = false;
				delete(it);
				player->screenArrows_.remove(it);
			}
			else if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup)
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
					SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
				{
					keyup = false;
					delete(it);
					player->screenArrows_.remove(it);
					player->feedbackLeft->addFeedback(Resources::FeedbackBad);
					cout << "flecha incorrecta" << endl;
					level->showError();
					player->errorLeft();
					player->resetCombo();
					player->addCalifications(0);
					numFailed++;

				}
			}
		}
	}
	if (!player->screenButtons_.empty())
	{
		auto it = player->screenButtons_.front();
		if (it != nullptr && abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 75)
		{
			if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup2)
			{
				if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 10)
				{
					cout << "perfecto" << endl;
					player->feedbackRight->addFeedback(Resources::FeedbackPerfect);
					player->hitRight->addHit(Resources::HitGold, it->getPosition());
					player->updateScoreNote(1);
					player->addCombo(1);
					player->addCalifications(3);
					if (numFailed >= 1)
						numFailed -= 1;

				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 25)
				{
					cout << "bien" << endl;
					player->feedbackRight->addFeedback(Resources::FeedbackGood);
					player->hitRight->addHit(Resources::HitSilver, it->getPosition());
					player->updateScoreNote(2);
					player->addCombo(1);
					player->addCalifications(2);
					if (numFailed >= 2)
						numFailed -= 2;
					else
						numFailed = 0;
				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 50)
				{
					cout << "regular" << endl;
					player->feedbackRight->addFeedback(Resources::FeedbackRegular);
					player->hitRight->addHit(Resources::HitCopper, it->getPosition());
					player->updateScoreNote(3);
					player->addCombo(1);
					player->addCalifications(1);
					if (numFailed >= 3)
						numFailed -= 3;
					else
						numFailed = 0;
				}
				else
				{
					cout << "mala punteria" << endl;
					player->feedbackRight->addFeedback(Resources::FeedbackBad);
					level->showError();
					player->errorRight();
					player->resetCombo();
					player->addCalifications(0);
					numFailed++;
				}
				delete it;
				player->screenButtons_.remove(it);
				keyup2 = false;
			}
			else if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup2)
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
					SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))
				{
					delete(it);

					player->feedbackRight->addFeedback(Resources::FeedbackBad);
					player->screenButtons_.remove(it);
					cout << "boton incorrecta" << endl;
					level->showError();
					player->errorRight();
					player->resetCombo();
					player->addCalifications(0);
					numFailed++;
				}
			}
		}
	}

	return ret;
}

