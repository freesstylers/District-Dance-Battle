#include "LevelInputManager.h"
#include "PlayState.h"


LevelInputManager::LevelInputManager(PlayState* l)
{
	level = l;
	keystates = SDL_GetKeyboardState(NULL);
	controller = SDL_GameControllerOpen(0);
}


LevelInputManager::~LevelInputManager()
{
}

void LevelInputManager::handleInput(Uint32 time, const SDL_Event& event) {

	if (!level->flechasPantalla_.empty()) 
	{
		auto it = level->flechasPantalla_.front();
		if (it != nullptr) {
			if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup)
			{
				keyup = false;
				if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY()) <= 25)
				{
					level->changeScoreInfo1(3);
				}
				else if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY()) <= 50)
				{
					level->changeScoreInfo1(2);
				}
				else if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY()) <= 100)
				{
					level->changeScoreInfo1(1);
				}
				else
				{
					level->changeScoreInfo1(0);
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
					level->changeScoreInfo1(0);
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
				keyup = false;
				if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY()) <= 25)
				{
					level->changeScoreInfo2(3);
				}
				else if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY()) <= 50)
				{
					level->changeScoreInfo2(2);
				}
				else if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY()) <= 100)
				{
					level->changeScoreInfo2(1);
				}
				else
				{
					level->changeScoreInfo2(0);
				}
				delete(it);
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
					level->changeScoreInfo2(0);
				}
			}
			if (event.type == SDL_CONTROLLERBUTTONUP) keyup2 = true;
		}
	}
}
