#include "PauseMenu.h"



PauseMenu::PauseMenu(SDLGame* game)
{
	double menuX = game->getDefaultWindowWidth() / 3;
	double menuY = game->getDefaultWindowHeight() / 6;
	double menuW = game->getDefaultWindowWidth() / 3;
	double menuH = game->getDefaultWindowHeight() * 2 / 3;


	bg = new EmptyObject(game, Vector2D(menuX, menuY), menuW, menuH, Resources::Blank);
	options = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuY / 4), menuW / 2, 50, Resources::Blank);
	Button* resume;
	Button* exit;

	op_bg = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuY / 4), menuW / 2, menuH / 2, Resources::Blank);
	Button* op_exit;
	Slider* music;
	Slider* sounds;
	Button* scale;
}


PauseMenu::~PauseMenu()
{
}
