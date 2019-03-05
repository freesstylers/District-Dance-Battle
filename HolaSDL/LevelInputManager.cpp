#include "LevelInputManager.h"
#include "PlayState.h"
#include "GameManager.h"


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

	if (!minigameActive) {
		if (!level->flechasPantalla_.empty())
		{
			auto it = level->flechasPantalla_.front();
			if (it != nullptr) {
				if (event.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, it->getKey()) && keyup)
				{
					keyup = false;
					if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY() ) <= 25)
					{
						cout << "perfecto" << endl;
					}
					else if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY() ) <= 50)
					{
						cout << "bien" << endl;
					}
					else if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY()) <= 100)
					{
						cout << "regular" << endl;
					}
					else
					{
						cout << "mala punteria" << endl;
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
					keyup = false;
					if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY()) <= 25)
					{
						cout << "perfecto" << endl;
					}
					else if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY() ) <= 50)
					{
						cout << "bien" << endl;
					}
					else if (abs(it->getPosition().getY() - level->leftPoint->getPosition().getY() ) <= 100)
					{
						cout << "regular" << endl;
					}
					else
					{
						cout << "mala punteria" << endl;
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
						cout << "flecha incorrecta" << endl;
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
			if (level->getMinigame()->botonesPantalla_.front()->getPosition().getX() < -3 || level->getMinigame()->botonesPantalla_.front()->getPosition().getX() > level->getGameManager()->getWindowWidth() || level->getMinigame()->botonesPantalla_.front()->getPosition().getY() < -3 || level->getMinigame()->botonesPantalla_.front()->getPosition().getY() > level->getGameManager()->getWindowHeight()) {
				level->getMinigame()->botonesPantalla_.pop_front();
				cout << "fuera" << endl;
				fallado = true;

			}
		}
	}
}
