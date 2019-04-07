#include "LevelInputManager.h"
#include "PlayState.h"
#include "GameManager.h"
#include <string>


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

void LevelInputManager::handleInput(Uint32 time, const SDL_Event& event) {

	if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup) {
		level->getGameManager()->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0);
		level->getGameManager()->getServiceLocator()->getAudios()->setChannelVolume(70);
	}

	if (!player->screenArrows_.empty())
	{
		auto it = player->screenArrows_.front();
			
		if (it != nullptr) 
		{
			if ((event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup)/* || event.type == SDL_KEYDOWN*/)
			{
				if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 10)
				{
					cout << "perfecto" << endl;
					level->feedbackLeft->addFeedback(Resources::FeedbackPerfect);
					level->updateScoreNote(1);
					player->addCombo(1);
				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 25)
				{
					cout << "bien" << endl;
					level->feedbackLeft->addFeedback(Resources::FeedbackGood);
					level->updateScoreNote(2);
					player->addCombo(1);
				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 50)
				{
					cout << "regular" << endl;
					level->feedbackLeft->addFeedback(Resources::FeedbackRegular);
					level->updateScoreNote(3);
					player->addCombo(1);
				}
				else
				{
					cout << "mala punteria" << endl;
					level->feedbackLeft->addFeedback(Resources::FeedbackBad);
					level->showError();
					player->errorLeft();
					player->resetCombo();
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
					level->feedbackLeft->addFeedback(Resources::FeedbackBad);
					cout << "flecha incorrecta" << endl;
					level->showError();
					player->errorLeft();
					player->resetCombo();
				}
			}
			else if (event.type == SDL_CONTROLLERBUTTONUP)
			{
				keyup = true;
			}
		}
	}
	if (!player->screenButtons_.empty())
	{
		auto it = player->screenButtons_.front();
		if (it != nullptr)
		{
			if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup2)
			{
				if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 10)
				{
					cout << "perfecto" << endl;
					level->feedbackRight->addFeedback(Resources::FeedbackPerfect);
					level->updateScoreNote(1);
					player->addCombo(1);

				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 25)
				{
					cout << "bien" << endl;
					level->feedbackRight->addFeedback(Resources::FeedbackGood);
					level->updateScoreNote(2);
					player->addCombo(1);
				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 50)
				{
					cout << "regular" << endl;
					level->feedbackRight->addFeedback(Resources::FeedbackRegular);
					level->updateScoreNote(3);
					player->addCombo(1);
				}
				else
				{
					cout << "mala punteria" << endl;
					level->feedbackRight->addFeedback(Resources::FeedbackBad);
					level->showError();
					player->errorRight();
					player->resetCombo();
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

					level->feedbackRight->addFeedback(Resources::FeedbackBad);
					player->screenButtons_.remove(it);
					cout << "boton incorrecta" << endl;
					level->showError();
					player->errorRight();
					player->resetCombo();
				}
			}
			else if (event.type == SDL_CONTROLLERBUTTONUP) keyup2 = true;
		}
	}
}

