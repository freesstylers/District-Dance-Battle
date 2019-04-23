#include "PauseMenu.h"
#include "PlayState.h"

PauseMenu::PauseMenu(SDLGame* game, PlayState* ps)
{

	level = ps;


	double menuX = game->getDefaultWindowWidth() / 3;
	double menuY = game->getDefaultWindowHeight() / 6;
	double menuW = game->getDefaultWindowWidth() / 3;
	double menuH = game->getDefaultWindowHeight() * 2 / 3;


	bg = new EmptyObject(game, Vector2D(menuX, menuY), menuW, menuH, Resources::MenuBG);

	resume = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH / 6), menuW / 2, 100, Resources::ButtonResume);

	restart = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH / 3), menuW / 2, 100, Resources::ButtonRestart);

	options = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH / 2), menuW / 2, 100, Resources::ButtonOptions);

	exit = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 2 / 3), menuW / 2, 100, Resources::ButtonExit);

	menuButtons.push_back(resume);
	menuButtons.push_back(restart);
	menuButtons.push_back(options);
	menuButtons.push_back(exit);


	op_bg = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuY / 4), menuW / 2, menuH / 2, Resources::Blank);
	op_exit = new EmptyObject(game, Vector2D(), menuW / 3, 100, Resources::Blank);
	EmptyObject* music;
	EmptyObject* sounds;
	scale = new EmptyObject(game, Vector2D(), menuW / 3, 100, Resources::Blank);

	controller = SDL_GameControllerOpen(0);

	timer = new TimerNoSingleton();


	selection = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 2 / 3), menuW / 2, 100, Resources::ButtonSelection);

}

PauseMenu::~PauseMenu()
{
	delete timer;
	delete bg;
	delete op_bg;
	delete selection;

	for (GameObject* g : menuButtons) {
		delete g;
	}
	for (GameObject* g : optionsButtons) {
		delete g;
	}
}

void PauseMenu::activate()
{
	selectedButton = 0;
	timer->Reset();
	optionsOpen = false;
	selection->setPosition(menuButtons[selectedButton]->getPosition());

	op_bg->setActive(false);
	for (EmptyObject* g : optionsButtons) {
		g->setActive(false);
	}
}

bool PauseMenu::handleInput(Uint32 time, const SDL_Event& event)
{
	if (active_)
	{
		if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYUP) {
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || event.key.keysym.sym == SDLK_UP) {
				selectedButton = (selectedButton == 0) ? 3 : selectedButton - 1;

				if(optionsOpen)
					selection->setPosition(optionsButtons[selectedButton]->getPosition());
				else
					selection->setPosition(menuButtons[selectedButton]->getPosition());
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || event.key.keysym.sym == SDLK_DOWN) {
				selectedButton = (selectedButton == 3) ? 0 : selectedButton + 1;

				if (optionsOpen)
					selection->setPosition(optionsButtons[selectedButton]->getPosition());
				else
					selection->setPosition(menuButtons[selectedButton]->getPosition());
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || event.key.keysym.sym == SDLK_RETURN) {
				switch (selectedButton) {
				case 0:
					resumeSong();
					return true;
					break;
				case 1:
					restartSong();
					break;
				case 2:
					toggleOptions();
					break;
				case 3:
					exitSong();
					break;
				default:
					break;
				}
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) || event.key.keysym.sym == SDLK_DELETE) {
				resumeSong();
				return true;
			}
		}
	}

	return false;
}

void PauseMenu::resumeSong()
{
	timer->Update();
	float time = timer->DeltaTime() * 1000;
	level->resume(time);
}

void PauseMenu::toggleOptions()
{
	//woot
	//wip
}

void PauseMenu::restartSong()
{
	level->restart();
}

void PauseMenu::exitSong()
{
	level->exit();
}


void PauseMenu::update(Uint32 time)
{
}

void PauseMenu::render(Uint32 time, bool beatSync)
{
	if (active_) {
		bg->render(time);
		for (EmptyObject* g : menuButtons) {
			g->render(time);
		}

		op_bg->render(time);
		for (EmptyObject* g : optionsButtons) {
			g->render(time);
		}

		selection->render(time);
	}
}

void PauseMenu::updateResolution(double wScale, double hScale)
{
	bg->updateResolution(wScale, hScale);
	for (EmptyObject* g : menuButtons) {
		g->updateResolution(wScale, hScale);
	}

	op_bg->updateResolution(wScale, hScale);
	for (EmptyObject* g : optionsButtons) {
		g->updateResolution(wScale, hScale);
	}

	selection->updateResolution(wScale, hScale);
}
