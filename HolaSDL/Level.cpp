#include "Level.h"

#include "PlayState.h"
#include "SRandBasedGenerator.h"
#include <cmath> // esto es C++
//#include <math.h> // esto es C

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
		Note* note2;
		file >> aux;
		int select=0;
		if (aux >= 0) {
			/*if (aux != 0) 
			{
				//If aux is going to change
				int probChange = random.nextInt(0, 10);
				if (probChange == 9) {
					//If aux change,it chooses the valor of aux
					int change = random.nextInt(0,1);
					aux = change+5;
				}
			}*/
			switch (aux) {
			case 0:
				
				note = nullptr;
				note2 = nullptr;
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, 50, 50, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, 50, 50, level->leftNotesVector2, noteVel);
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, 50, 50, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, 50, 50, level->leftNotesVector2, noteVel);
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, 50, 50, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, 50, 50, level->leftNotesVector2, noteVel);
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, 50, 50, level->leftNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, 50, 50, level->leftNotesVector2, noteVel);
				break;
			default:
				break;
			}
			level->levelArrows_.push_back(note);
			level->levelArrows2_.push_back(note2);

			if(aux!=0) noteAmount++;
		}
	}

	aux = 0;

	while (aux >= 0) {
		Note* note;
		int select=0;
		Note* note2;
		file >> aux;
		if (aux >= 0) {
			/*if (aux != 0) {
				
				int probChange = random.nextInt(0, 10);
				if (probChange == 9) {
					int change = random.nextInt(0,1);
					aux = change+5;
				}
			}*/
			switch (aux) {
			case 0:
				
				note = nullptr;
				note2 = nullptr;
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_A, gm, 50, 50, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_A, gm, 50, 50, level->rightNotesVector2, noteVel);
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_B, gm, 50, 50, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_B, gm, 50, 50, level->rightNotesVector2, noteVel);
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_X, gm, 50, 50, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_X, gm, 50, 50, level->rightNotesVector2, noteVel);
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_Y, gm, 50, 50, level->rightNotesVector, noteVel);
				note2 = new Note(SDL_CONTROLLER_BUTTON_Y, gm, 50, 50, level->rightNotesVector2, noteVel);
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

