#include "Level.h"

#include "PlayState.h"
#include <math.h>

Level::Level(PlayState* l, SDLGame* gam, string n)
{
	level = l;
	gm = gam;
	name = n;
}


Level::~Level()
{
}

void Level::playSong() {
	level->playSong(song);
}

void Level::init() {
	ifstream file("resources/levels/" + name + ".txt");
	file >> bpm;
	file >> songLength;
	file >> song;

	velFlechas = level->asignaVel(60000/bpm);

	int aux;
	Flechas* flecha;
	for (int i = 0; i < round(bpm*(songLength/60)); i++) {
		file >> aux;
		switch (aux) {
		case 0:
			flecha = nullptr;
			break;
		case 1:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, 50, 50, level->leftNotesVector, velFlechas);
			break;
		case 2:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, 50, 50, level->leftNotesVector, velFlechas);
			break;
		case 3:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, 50, 50, level->leftNotesVector, velFlechas);
			break;
		case 4:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, 50, 50, level->leftNotesVector, velFlechas);
			break;
		}
		level->flechasNivel_.push_back(flecha);

		numNotas++;
	}
	for (int i = 0; i < round(bpm*(songLength/60)); i++) {
		file >> aux;
		switch (aux) {
		case 0:
			flecha = nullptr;
			break;
		case 1:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_A, gm, 50, 50, level->rightNotesVector, velFlechas);
			break;
		case 2:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_B, gm, 50, 50, level->rightNotesVector, velFlechas);
			break;
		case 3:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_X, gm, 50, 50, level->rightNotesVector, velFlechas);
			break;
		case 4:
			flecha = new Flechas(SDL_CONTROLLER_BUTTON_Y, gm, 50, 50, level->rightNotesVector, velFlechas);
			break;
		}
		level->botonesNivel_.push_back(flecha);

		numNotas++;
	}
	file.close();


}
