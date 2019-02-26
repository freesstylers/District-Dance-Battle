#include "Level.h"

#include "PlayState.h"

Level::Level(PlayState* l, string n)
{
	level = l;
	name = n;
	init(n);
}


Level::~Level()
{
}

void Level::playSong() {
	level->playSong(song);
}

void Level::init(string n) {
	ifstream file("resources/levels/" + name + ".txt");
	file >> bpm;
	file >> tiempo;
	file >> probqte;
	velFlechas = level->asignaVel(60000 / bpm);

	int aux;
	Flechas* flecha;
	for (int i = 0; i < 25; i++) {
		file >> aux;
		switch (aux) {
		case 1:
			flecha = new Flechas(SDL_SCANCODE_LEFT, level->manager, 50, 50, level->posFlechaInicial, velFlechas);
			break;
		case 2:
			flecha = new Flechas(SDL_SCANCODE_RIGHT, level->manager, 50, 50, level->posFlechaInicial, velFlechas);
			break;
		case 3:
			flecha = new Flechas(SDL_SCANCODE_UP, level->manager, 50, 50, level->posFlechaInicial, velFlechas);
			break;
		case 4:
			flecha = new Flechas(SDL_SCANCODE_DOWN, level->manager, 50, 50, level->posFlechaInicial, velFlechas);
			break;
		}
		level->flechasNivel_.push_back(flecha);
	}
	for (int i = 0; i < 25; i++) {
		file >> aux;
		switch (aux) {
		case 1:
			flecha = new Flechas(SDL_SCANCODE_A, level->manager, 50, 50, level->posBotonInicial, velFlechas);
			break;
		case 2:
			flecha = new Flechas(SDL_SCANCODE_B, level->manager, 50, 50, level->posBotonInicial, velFlechas);
			break;
		case 3:
			flecha = new Flechas(SDL_SCANCODE_X, level->manager, 50, 50, level->posBotonInicial, velFlechas);
			break;
		case 4:
			flecha = new Flechas(SDL_SCANCODE_Y, level->manager, 50, 50, level->posBotonInicial, velFlechas);
			break;
		}
		level->botonesNivel_.push_back(flecha);
	}
	file.close();


}
