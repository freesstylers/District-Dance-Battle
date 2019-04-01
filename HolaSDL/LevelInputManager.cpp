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

		if (!player->screenArrows_.empty())
		{
			auto it = player->screenArrows_.front();
			
			if (it != nullptr) 
			{
				if (player->x == 5)
				{
						if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) ||
							SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) ||
							SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
							SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
						{
							cout << "bomba" << endl;
							player->selectScreenArrows.pop_front();
							delete(it);
							player->screenArrows_.remove(it);
							if (level->getScore() >= 1)
							{
								level->scoreBar->updateBar(-1);
								level->updateScore(-1);
							}
							level->feedbackLeft->addFeedback(Resources::FeedbackBad);
							level->showError();
						}
				}
				else 
				{
					if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup)
					{
						if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 10)
						{
							cout << "perfecto" << endl;
							level->feedbackLeft->addFeedback(Resources::FeedbackPerfect);
							level->scoreBar->updateBar(1);
							level->updateScore(1);
						}
						else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 25)
						{
							cout << "bien" << endl;
							level->feedbackLeft->addFeedback(Resources::FeedbackGood);
							level->scoreBar->updateBar(2);
							level->updateScore(2);
						}
						else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 50)
						{
							cout << "regular" << endl;
							level->feedbackLeft->addFeedback(Resources::FeedbackRegular);
							level->scoreBar->updateBar(3);
							level->updateScore(3);
						}
						else
						{
							cout << "mala punteria" << endl;
							level->feedbackLeft->addFeedback(Resources::FeedbackBad);
							level->showError();
						}
						keyup = false;
						delete(it);
						player->selectScreenArrows.pop_front();
						player->screenArrows_.remove(it);
					}
					else if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup)
					{
						if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
							SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
						{
							keyup = false;
							delete(it);
							player->selectScreenArrows.pop_front();
							player->screenArrows_.remove(it);
							level->feedbackLeft->addFeedback(Resources::FeedbackBad);
							cout << "flecha incorrecta" << endl;
							level->showError();
						}
					}
					else if (event.type == SDL_CONTROLLERBUTTONUP)
					{
						keyup = true;
					}
				}

			}
		}
		if (!player->screenButtons_.empty())
		{
				auto it = player->screenButtons_.front();
				if (it != nullptr)
				{
					if (player->y == 5)
					{
						if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup)
						{

							if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) ||
								SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
								SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y) ||
								SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X))
							{
								cout << "bomba" << endl;
								player->selectScreenButtons.pop_front();
								delete(it);
								player->screenButtons_.remove(it);
								if (level->getScore() >= 1)
								{
									level->scoreBar->updateBar(-1);
									level->updateScore(-1);
								}
								level->feedbackRight->addFeedback(Resources::FeedbackBad);
								level->showError();
							}
						}
						
					}
					else 
					{
						if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup2)
						{
							if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 10)
							{
								cout << "perfecto" << endl;
								level->feedbackRight->addFeedback(Resources::FeedbackPerfect);
								level->scoreBar->updateBar(1);
								level->updateScore(1);

							}
							else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 25)
							{
								cout << "bien" << endl;
								level->feedbackRight->addFeedback(Resources::FeedbackGood);
								level->scoreBar->updateBar(2);
								level->updateScore(2);
							}
							else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 50)
							{
								cout << "regular" << endl;
								level->feedbackRight->addFeedback(Resources::FeedbackRegular);
								level->scoreBar->updateBar(3);
								level->updateScore(3);
							}
							else
							{
								cout << "mala punteria" << endl;
								level->feedbackRight->addFeedback(Resources::FeedbackBad);
								level->showError();
								level->errorLeft();
							}
							delete it;
							player->selectScreenButtons.pop_front();
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
								player->selectScreenButtons.pop_front();
								player->screenButtons_.remove(it);
								cout << "boton incorrecta" << endl;
								level->showError();
								level->errorLeft();
							}
						}
						else if (event.type == SDL_CONTROLLERBUTTONUP) keyup2 = true;
					}
				}
		}
}

