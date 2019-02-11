#include "PlayState.h"

PlayState::PlayState(Game* g) :GameState(g)
{
	game = g;

	//Creamos todos los objetos del juego (escena PlayState)

	//if (mode == 0)
		newGame();
	//else if (mode == 1)
		loadSave();
}

void PlayState::newGame() 
{
}


PlayState::~PlayState()
{
}

void PlayState::update()
{
	//GameState::update();
}

bool PlayState::handleEvent(SDL_Event e)
{
	/*if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
		cout << "Menu de pausa" << endl;
		app->getMachine()->pushState(new PauseState(app));
		return true;
	}
	else {

		if (e.type == SDL_QUIT) {
			game->exit();
			return true;
		}

		if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
			paddle->handleEvents(e);
			return true;
		}
	}
	*/
	return false;
}

void PlayState::saveGame(int code) //puntero a ball, paddle y blocksmap
{
}

void PlayState::DeleteAll()
{
	stage.clear();
}

void PlayState::loadSave()
{
}