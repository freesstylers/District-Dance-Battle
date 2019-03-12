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

	noteVel = level->setVel(60000/bpm);

	int aux = 0;

	while (aux >= 0) {
		Note* note;
		file >> aux;

		if (aux >= 0) {
			switch (aux) {
			case 0:
				note = nullptr;
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, 50, 50, level->leftNotesVector, noteVel);
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, 50, 50, level->leftNotesVector, noteVel);
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, 50, 50, level->leftNotesVector, noteVel);
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, 50, 50, level->leftNotesVector, noteVel);
				break;
			default:
				break;
			}
			level->levelArrows_.push_back(note);

			if(aux!=0) noteAmount++;
		}
	}

	aux = 0;

	while (aux >= 0) {
		Note* note;
		file >> aux;

		if (aux >= 0) {
			switch (aux) {
			case 0:
				note = nullptr;
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_A, gm, 50, 50, level->rightNotesVector, noteVel);
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_B, gm, 50, 50, level->rightNotesVector, noteVel);
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_X, gm, 50, 50, level->rightNotesVector, noteVel);
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_Y, gm, 50, 50, level->rightNotesVector, noteVel);
				break;
			default:
				break;
			}

			level->levelButtons_.push_back(note);

			if (aux != 0) noteAmount++;
		} 
	}
	file.close();


}
