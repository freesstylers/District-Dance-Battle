#include "LevelInputManager.h"
#include "PlayState.h"
#include "GameManager.h"
#include <string>
#include "PlayerPack.h"

#include "Tracker.h"


LevelInputManager::LevelInputManager(PlayState* l, PlayerPack* pl, int numctrl, int ControllerMode_)
{
	numctrl_ = numctrl;
	level = l;
	player = pl;
	keystates = SDL_GetKeyboardState(NULL); //esto no se que hace, se puede quitar?
	ControllerMode = ControllerMode_;

	if (ControllerMode_ != 3)
		controller = SDL_GameControllerOpen(numctrl_);
}

LevelInputManager::~LevelInputManager()
{
}

bool LevelInputManager::handleInput(Uint32 time, const SDL_Event& event) {


	///////////////////////////////////////////////////    TELEMETRIA       /////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////		variables		/////////////////////////////////////////////////////////////////////////////////
	InputEvent::InputButton playerButton;
	InputEvent::InputButton levelButton;
	float distance = 0.0f;
	int numNote = 0;
	///////////////////////////////////////////////////    TELEMETRIA       /////////////////////////////////////////////////////////////////////////////////


	bool ret = false;
	SDL_GameControllerButton buttons = SDL_CONTROLLER_BUTTON_INVALID;
	SDL_GameControllerButton arrows = SDL_CONTROLLER_BUTTON_INVALID;
	if (ControllerMode == 3) {
		switch (event.key.keysym.sym)
		{
		case SDLK_DOWN:
			buttons = SDL_CONTROLLER_BUTTON_A;
			playerButton = InputEvent::InputButton::rDown;
			break;
		case SDLK_UP:
			buttons = SDL_CONTROLLER_BUTTON_Y;
			playerButton = InputEvent::InputButton::rUp;
			break;
		case SDLK_LEFT:
			buttons = SDL_CONTROLLER_BUTTON_X;
			playerButton = InputEvent::InputButton::rLeft;
			break;
		case SDLK_RIGHT:
			buttons = SDL_CONTROLLER_BUTTON_B;
			playerButton = InputEvent::InputButton::rRight;
			break;
		case SDLK_s:
			arrows = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
			playerButton = InputEvent::InputButton::lDown;
			break;
		case SDLK_w:
			arrows = SDL_CONTROLLER_BUTTON_DPAD_UP;
			playerButton = InputEvent::InputButton::lUp;
			break;
		case SDLK_a:
			arrows = SDL_CONTROLLER_BUTTON_DPAD_LEFT;
			playerButton = InputEvent::InputButton::lLeft;
			break;
		case SDLK_d:
			arrows = SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
			playerButton = InputEvent::InputButton::lRight;
			break;
		default:
			break;
		}

		if(event.type == SDL_CONTROLLERBUTTONDOWN && !(SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK)))
			return ret;
	}
	else if (event.type == SDL_KEYDOWN && !(event.key.keysym.sym == SDLK_TAB || event.key.keysym.sym == SDLK_ESCAPE))
			return ret;

	if (keyup && (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN)) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
			SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) ||
			event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_w ||
			SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
			SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y) ||
			event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_UP) {
			level->getGameManager()->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0, 1);
		}
	}

	if (event.type == SDL_CONTROLLERBUTTONUP || event.type == SDL_KEYUP)
	{
		keyup = true;
		keyup2 = true;
	}

	if ((blockpause < time - 500) && ((event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN) && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) || event.key.keysym.sym == SDLK_TAB || event.key.keysym.sym == SDLK_ESCAPE))) {
		ret = ret || level->pause();
		blockpause = 0;
	}

	//inputs for the d-pad
	if (!player->screenArrows_.empty())
	{
		auto it = player->screenArrows_.front();
		if (it != nullptr && abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 100)
		{
			
			
			///////////////////////////////////////////////////    TELEMETRIA       /////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////// Flechas del nivel   /////////////////////////////////////////////////////////////////////////////////
			distance = abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2));
			switch (it->getKey()) {
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				levelButton = InputEvent::InputButton::lLeft;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				levelButton = InputEvent::InputButton::lRight;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_UP:
				levelButton = InputEvent::InputButton::lUp;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_DOWN:
				levelButton = InputEvent::InputButton::lDown;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_X:
				levelButton = InputEvent::InputButton::rLeft;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_B:
				levelButton = InputEvent::InputButton::rRight;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_Y:
				levelButton = InputEvent::InputButton::rUp;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A:
				levelButton = InputEvent::InputButton::rDown;
				break;
			}
			///////////////////////////////////////////////////    TELEMETRIA       /////////////////////////////////////////////////////////////////////////////////
			


			if ((event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN) && keyup && (SDL_GameControllerGetButton(controller, it->getKey()) ||  (ControllerMode == 3 && it->getKey() == arrows)))
			{
				if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 10)
				{
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
					player->feedbackLeft->addFeedback(Resources::FeedbackBad);
					level->showError();
					player->resetCombo();
					player->addCalifications(0);
					if (it->getKey() != SDL_CONTROLLER_BUTTON_INVALID)
						numFailed++;
				}
				keyup = false;
				delete(it);
				player->screenArrows_.remove(it);
			}
			else if (event.type == SDL_CONTROLLERBUTTONDOWN && keyup || event.type == SDL_KEYDOWN && keyup)
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
					SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || keyPressed(arrows, false))
				{
					keyup = false;
					delete(it);
					player->screenArrows_.remove(it);
					player->feedbackLeft->addFeedback(Resources::FeedbackBad);
					level->showError();
					player->resetCombo();
					player->addCalifications(0);
					if (it->getKey() != SDL_CONTROLLER_BUTTON_INVALID)
						numFailed++;

				}
			}
		}


		///////////////////////////////////////////////////    TELEMETRIA       /////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////    enviar eventos   /////////////////////////////////////////////////////////////////////////////////
		Tracker* tracker = Tracker::GetInstance();

		InputEvent e = InputEvent(time_t(0));
		//e.setPlayerButton(playerButton);
		//e.setLevelButton(levelButton);
		//e.setDistance(distance);
		//e.setNLevel(level->getNLevel());

		//tracker->trackEvent(e);

		//std::cout << "Event tracked: " << playerButton << std::endl;
		///////////////////////////////////////////////////    TELEMETRIA       /////////////////////////////////////////////////////////////////////////////////


	}

	//inputs for the buttons
	if (!player->screenButtons_.empty())
	{
		auto it = player->screenButtons_.front();
		if (it != nullptr && abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getLeftPoint()->getPosition().getY() + player->getLeftPoint()->getHeight() / 2)) <= 75)
		{
			if ((event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN) && keyup2 &&( SDL_GameControllerGetButton(controller, it->getKey()) || (ControllerMode == 3 && it->getKey() == buttons)))
			{
				if (abs((it->getPosition().getY() + it->getHeight() / 2) - (player->getRightPoint()->getPosition().getY() + player->getRightPoint()->getHeight() / 2)) <= 10)
				{
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
					player->feedbackRight->addFeedback(Resources::FeedbackBad);
					level->showError();
					player->resetCombo();
					player->addCalifications(0);
					if (it->getKey() != SDL_CONTROLLER_BUTTON_INVALID)
						numFailed++;
				}
				delete it;
				player->screenButtons_.remove(it);
				keyup2 = false;
			}
			else if ((event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN) && keyup2)
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
					SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y) || keyPressed(buttons, true))
				{
					delete(it);

					player->feedbackRight->addFeedback(Resources::FeedbackBad);
					player->screenButtons_.remove(it);
					level->showError();
					player->resetCombo();
					player->addCalifications(0);
					if (it->getKey() != SDL_CONTROLLER_BUTTON_INVALID)
						numFailed++;
				}
			}
		}
	}

	return ret;
}

bool LevelInputManager::keyPressed(SDL_GameControllerButton buttons, bool areButtons)
{
	if (areButtons) {
		return (buttons == SDL_CONTROLLER_BUTTON_A || buttons == SDL_CONTROLLER_BUTTON_Y || buttons == SDL_CONTROLLER_BUTTON_X ||
			buttons == SDL_CONTROLLER_BUTTON_B);
	}
	else {
		return (buttons == SDL_CONTROLLER_BUTTON_DPAD_LEFT || buttons == SDL_CONTROLLER_BUTTON_DPAD_UP || buttons == SDL_CONTROLLER_BUTTON_DPAD_DOWN ||
			buttons == SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
	}

}