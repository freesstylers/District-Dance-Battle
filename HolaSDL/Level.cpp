#include "Level.h"

#include "PlayState.h"
#include "SRandBasedGenerator.h"
#include <cmath> // esto es C++
//#include <math.h> // esto es C

Level::Level(PlayState* l, SDLGame* gam, string n, int noteSize)
{
	level = l;
	gm = gam;
	name = n;
	noteSize_ = noteSize;
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
		Note* note2;
		file >> aux;
		int select=0;
		if (aux >= 0) {
			switch (aux) {
			case 0:
				select = -1;
				note = nullptr;
				note2 = nullptr;
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel);
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel);
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel);
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel);
				break;
			case 5:
				note = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel);
				break;
			default:
				break;
			}
			level->levelArrows_.push_back(note);
			level->levelArrows2_.push_back(note2);

			if(aux != 0) noteAmount++;
		}
	}

	aux = 0;

	while (aux >= 0) {
		Note* note;
		int select=0;
		Note* note2;
		file >> aux;
		if (aux >= 0) {
			switch (aux) {
			case 0:
				select = -1;
				note = nullptr;
				note2 = nullptr;
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_A, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_A, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel);
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_B, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_B, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel);
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_X, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_X, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel);
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_Y, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_Y, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel);
				break;
			case 5:
				note = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel);
				break;
			default:
				break;
			}
			level->levelButtons_.push_back(note);
			level->levelButtons2_.push_back(note2);

			if (aux != 0) noteAmount++;
		} 
	}
	file.close();


}

