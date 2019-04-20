#include "PauseMenu.h"



void PauseMenu::resumeSong()
{
}

void PauseMenu::toggleOptions()
{
}

void PauseMenu::restartSong()
{
}

void PauseMenu::exitSong()
{
}

PauseMenu::PauseMenu(SDLGame* game)
{
	double menuX = game->getDefaultWindowWidth() / 3;
	double menuY = game->getDefaultWindowHeight() / 6;
	double menuW = game->getDefaultWindowWidth() / 3;
	double menuH = game->getDefaultWindowHeight() * 2 / 3;


	bg = new EmptyObject(game, Vector2D(menuX, menuY), menuW, menuH, Resources::Panel);

	resume = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH / 6), menuW / 2, 50, Resources::EffectVaporWave);

	restart = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH / 3), menuW / 2, 50, Resources::EffectVaporWave);

	options = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH / 2), menuW / 2, 50, Resources::EffectVaporWave);

	exit = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 2 / 3), menuW / 2, 50, Resources::EffectVaporWave);

	menuButtons.push_back(bg);
	menuButtons.push_back(resume);
	menuButtons.push_back(restart);
	menuButtons.push_back(options);
	menuButtons.push_back(exit);


	op_bg = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuY / 4), menuW / 2, menuH / 2, Resources::Blank);
	op_exit = new EmptyObject(game, Vector2D(), menuW / 3, 50, Resources::Blank);
	Slider* music;
	Slider* sounds;
	scale = new EmptyObject(game, Vector2D(), menuW / 3, 50, Resources::Blank);

	controller = SDL_GameControllerOpen(0);

}


PauseMenu::~PauseMenu()
{
}

bool PauseMenu::handleInput(Uint32 time, const SDL_Event& event)
{
	if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN) {
		if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || event.key.keysym.sym == SDLK_UP) {
			selectedButton = (selectedButton - 1) % 5;
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || event.key.keysym.sym == SDLK_DOWN) {
			selectedButton = (selectedButton + 1) % 5;
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || event.key.keysym.sym == SDLK_RETURN) {
			switch (selectedButton) {
			case 0:
				resumeSong();
			case 1:
				restartSong();
			case 2:
				toggleOptions();
			case 3:
				exitSong();
			}
		}
		else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) || event.key.keysym.sym == SDLK_DELETE) {
			resumeSong();
		}
	}


	return false;
}

void PauseMenu::update(Uint32 time)
{
}

void PauseMenu::render(Uint32 time, bool beatSync)
{
	for (GameObject* g : menuButtons) {
		g->render(time);
	}
}

void PauseMenu::updateResolution(double wScale, double hScale)
{
	for (GameObject* g : menuButtons) {
		g->updateResolution(wScale, hScale);
	}
}
