#include "LevelInputManager.h"
#include "PlayState.h"


LevelInputManager::LevelInputManager(PlayState* l)
{
	level = l;
	keystates = SDL_GetKeyboardState(NULL);
}


LevelInputManager::~LevelInputManager()
{
}

void LevelInputManager::handleInput(Uint32 time, const SDL_Event& event) {

	if (!level->flechasPantalla_.empty()) 
	{
		auto it = level->flechasPantalla_.front();
		if (it != nullptr) {
			if (event.type == SDL_KEYDOWN && keystates[it->getKey()] && keyup)
			{
				keyup = false;
				if (abs(it->getPosition().getY() - level->punto->getPosition().getY()) <= 25)
				{
					cout << "perfecto" << endl;
				}
				else if (abs(it->getPosition().getY() - level->punto->getPosition().getY()) <= 50)
				{
					cout << "bien" << endl;
				}
				else if (abs(it->getPosition().getY() - level->punto->getPosition().getY()) <= 100)
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
			/*else if (event.type == SDL_KEYDOWN && keyup)
			{
				keyup = false;
				delete(it);
				level->flechasPantalla_.remove(it);
				cout << "flecha incorrecta" << endl;
			}*/
			if (event.type == SDL_KEYUP) keyup = true;
		}
	}
	if (!level->botonesPantalla_.empty())
	{
		auto it = level->botonesPantalla_.front();
		if (it != nullptr) {
			if (event.type == SDL_KEYDOWN && keystates[it->getKey()] && keyup2)
			{
				keyup = false;
				if (abs(it->getPosition().getY() - level->punto->getPosition().getY()) <= 25)
				{
					cout << "perfecto" << endl;
				}
				else if (abs(it->getPosition().getY() - level->punto->getPosition().getY()) <= 50)
				{
					cout << "bien" << endl;
				}
				else if (abs(it->getPosition().getY() - level->punto->getPosition().getY()) <= 100)
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
			/*else if (event.type == SDL_KEYDOWN && keyup2)
			{
				keyup2 = false;
				delete(it);
				level->botonesPantalla_.remove(it);
				cout << "flecha incorrecta" << endl;
			}*/
			if (event.type == SDL_KEYUP) keyup2 = true;
		}
	}
}
