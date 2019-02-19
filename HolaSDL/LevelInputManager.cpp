#include "LevelInputManager.h"
#include "PlayState.h"


LevelInputManager::LevelInputManager(PlayState* l)
{
	level = l;
}


LevelInputManager::~LevelInputManager()
{
}

void LevelInputManager::handleInput(Uint32 time, const SDL_Event& event) {

	if (!level->flechasPantalla_.empty()) {
		auto it = level->flechasPantalla_.front();
		if (it != nullptr) {
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == it->getKey() && keyup)
			{
				keyup = false;
				if (abs(it->getPosition().getX() - level->punto->getPosition().getX()) <= 25)
				{
					cout << "perfecto" << endl;
				}
				else if (abs(it->getPosition().getX() - level->punto->getPosition().getX()) <= 50)
				{
					cout << "bien" << endl;
				}
				else if (abs(it->getPosition().getX() - level->punto->getPosition().getX()) <= 100)
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
			else if (event.type == SDL_KEYDOWN && keyup)
			{
				keyup = false;
				delete(it);
				level->flechasPantalla_.remove(it);
				cout << "flecha incorrecta" << endl;
			}
			if (event.type == SDL_KEYUP) keyup = true;
		}
	}
}
