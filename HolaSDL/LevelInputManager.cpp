#include "LevelInputManager.h"
#include "PlayState.h"
#include "GameManager.h"


LevelInputManager::LevelInputManager(PlayState* l, int numctrl)
{
	numctrl_ = numctrl;
	level = l;
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(numctrl_);
}


LevelInputManager::~LevelInputManager()
{
}

void LevelInputManager::handleInput(Uint32 time, const SDL_Event& event) {

	if (!minigameActive) {
		if (!level->flechasPantalla_.empty())
		{
			auto it = level->flechasPantalla_.front();
			if (it != nullptr) {
				if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup)
				{
					keyup = false;
					if (abs((it->getPosition().getY() + it->getHeight() / 2) - (level->rightPoint->getPosition().getY() + level->rightPoint->getHeight() / 2)) <= 25)
					{
						cout << "perfecto" << endl;
						level->feedbackLeft->queueAnimationChange(Resources::FeedbackPerfect);
					}
					else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (level->rightPoint->getPosition().getY() + level->rightPoint->getHeight() / 2)) <= 50)
					{
						cout << "bien" << endl;
						level->feedbackLeft->queueAnimationChange(Resources::FeedbackGood);
					}
					else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (level->rightPoint->getPosition().getY() + level->rightPoint->getHeight() / 2)) <= 100)
					{
						cout << "regular" << endl;
						level->feedbackLeft->queueAnimationChange(Resources::FeedbackRegular);
					}
					else
					{
						cout << "mala punteria" << endl;
						level->feedbackLeft->queueAnimationChange(Resources::FeedbackBad);
					}
						delete(it);
						level->flechasPantalla_.remove(it);
					
				}
				else if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup)
				{
					if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
						SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
					{
						keyup = false;
						delete(it);
						level->flechasPantalla_.remove(it);
						level->feedbackLeft->queueAnimationChange(Resources::FeedbackBad);
						cout << "flecha incorrecta" << endl;
					}
				}
				if (event.type == SDL_CONTROLLERBUTTONUP) keyup = true;
			}
		}
		if (!level->botonesPantalla_.empty())
		{
				auto it = level->botonesPantalla_.front();
		if (it != nullptr) {
			if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup2)
			{
				keyup2 = false;
				if (abs((it->getPosition().getY() + it->getHeight()/2) - (level->rightPoint->getPosition().getY() + level->rightPoint->getHeight()/2)) <= 25)
				{
					cout << "perfecto" << endl;
					level->feedbackRight->queueAnimationChange(Resources::FeedbackPerfect);
				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (level->rightPoint->getPosition().getY() + level->rightPoint->getHeight() / 2)) <= 50)
				{
					cout << "bien" << endl;
					level->feedbackRight->queueAnimationChange(Resources::FeedbackGood);
				}
				else if (abs((it->getPosition().getY() + it->getHeight() / 2) - (level->rightPoint->getPosition().getY() + level->rightPoint->getHeight() / 2)) <= 100)
				{
					cout << "regular" << endl;
					level->feedbackRight->queueAnimationChange(Resources::FeedbackRegular);
				}
				else
				{
						cout << "mala punteria" << endl;
						level->feedbackRight->queueAnimationChange(Resources::FeedbackBad);
				}
	
					level->botonesPantalla_.remove(it);
				}
				else if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup2)
				{
					if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
						SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))
					{
						keyup2 = false;
						delete(it);
						level->botonesPantalla_.remove(it);
						level->feedbackRight->queueAnimationChange(Resources::FeedbackRegular);
						cout << "boton incorrecta" << endl;
					}
				}
				if (event.type == SDL_CONTROLLERBUTTONUP) keyup2 = true;
			}
		}
	}
	else {

		if (!level->getMinigame()->botonesPantalla_.empty())
		{
			auto it = level->getMinigame()->botonesPantalla_.front();
			if (it != nullptr) {
				if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup2)
				{
					keyup = false;
					if (abs(it->getPosition().getY()) > 0 && abs(it->getPosition().getY()) < level->leftPoint->getGame()->getWindowHeight() && abs(it->getPosition().getX()) > 0 && abs(it->getPosition().getX()) < level->leftPoint->getGame()->getWindowWidth())
					{
						cout << "perfecto" << endl;
						fallado = false;
					}
					

					delete(it);
					level->getMinigame()->botonesPantalla_.remove(it);
				}
				else if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup2)
				{
					if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
						SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))
					{
						keyup2 = false;
						delete(it);
						level->getMinigame()->botonesPantalla_.remove(it);
						cout << "flecha incorrecta" << endl;
						fallado = true;
					}
				}
				if (event.type == SDL_CONTROLLERBUTTONUP) keyup2 = true;
			}
			
		}
		
		
	}
}
void LevelInputManager::update() {
	if (minigameActive) {
		if (!level->getMinigame()->botonesPantalla_.empty())
		{
			if (level->getMinigame()->botonesPantalla_.front()->getPosition().getX() < -3 || level->getMinigame()->botonesPantalla_.front()->getPosition().getX() > level->getGameManager()->getWindowWidth() || level->getMinigame()->botonesPantalla_.front()->getPosition().getY() < -75 || level->getMinigame()->botonesPantalla_.front()->getPosition().getY() > level->getGameManager()->getWindowHeight() +75) {
				level->getMinigame()->botonesPantalla_.pop_front();
				cout << "fuera" << endl;
				fallado = true;

			}
		}
	}
}
