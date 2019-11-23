#include "Level.h"

#include "GameManager.h"
#include "PlayState.h"
#include "SRandBasedGenerator.h"
#include <cmath>

Level::Level(PlayState* l, SDLGame* gam, string n, int noteSize)
{
	level = l;
	gm = gam;
	name = n;
	noteSize_ = noteSize;

}


Level::~Level()
{
	for (Note* o : level->levelArrows_) 
	{
		delete o;
		o = nullptr;
	}
	for (Note* o : level->levelArrows2_) 
	{
		delete o;	
		o = nullptr;
	}
	for (Note* o : level->levelButtons_) 
	{
		delete o;
		o = nullptr;
	}
	for (Note* o : level->levelButtons2_) 
	{
		delete o;
		o = nullptr;
	}
}

void Level::playSong() {
	level->playSong(song);
}

void Level::RandomLevel()
{
	srand(time(NULL));

	bpm = 330;
	songLength = 125;
	song = 26;
	noteVel = level->setVel(60000 / (double)bpm);


	float count = bpm * (songLength / 60.0f);
	float c = 0;

	while (c < count)
	{
		int aux = 0;
		Note* note;
		Note* note2;
		int select = 0;

		float nextProb = rand() % 100; //entre 0 y 100

		if (nextProb < 75)
		{
			aux = 0;
		}
		else
		{
			aux = rand() % 4 + 1;
		}

		switch (aux) {
		case 0:
			select = -1;
			note = nullptr;
			note2 = nullptr;
			break;
		case 1:
			note = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		case 2:
			note = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		case 3:
			note = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		case 4:
			note = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		case 5:
			note = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		default:
			break;
		}
		level->levelArrows_.push_back(note);
		level->levelArrows2_.push_back(note2);

		if (aux != 0) 
			noteAmount++;
		c++;
	}

	c = 0;

	while (c < count)
	{
		int aux = 0;
		Note* note;
		Note* note2;
		int select = 0;

		float nextProb = rand() % 100; //entre 0 y 100

		if (nextProb < 75)
		{
			aux = 0;
		}
		else
		{
			aux = rand() % 4 + 1;
		}

		switch (aux) {
		case 0:
			select = -1;
			note = nullptr;
			note2 = nullptr;
			break;
		case 1:
			note = new Note(SDL_CONTROLLER_BUTTON_A, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_A, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		case 2:
			note = new Note(SDL_CONTROLLER_BUTTON_B, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_B, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		case 3:
			note = new Note(SDL_CONTROLLER_BUTTON_X, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_X, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		case 4:
			note = new Note(SDL_CONTROLLER_BUTTON_Y, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_Y, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		case 5:
			note = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
			note2 = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
			break;
		default:
			break;
		}
		level->levelButtons_.push_back(note);
		level->levelButtons2_.push_back(note2);

		if (aux != 0) 
			noteAmount++;
		c++;

	}
}


void Level::init(bool hardmode) {

	if (hardmode) name = name + "Hard";

	ifstream file("resources/levels/" + name + ".txt");
	file >> bpm;
	file >> songLength;
	file >> song;

	if (!hardmode) {
		if (name == "asereje")
			noteVel = level->setVel(60000 / ((double)bpm / 1.5));
		else if (name == "rock" || name == "hardbass")
			noteVel = level->setVel(60000 / ((double)bpm / 2));
		else
			noteVel = level->setVel(60000 / (double)bpm);
	}
	else {
		if (name == "vaporwaveHard" || name == "reggeatonHard" || name == "hiphopHard" || name == "hardbass")
			noteVel = level->setVel(60000 / ((double)bpm * 2));
		else
			noteVel = level->setVel(60000 / (double)bpm);
	}

	int aux = 0;
	while (aux >= 0) {
		Note* note;
		Note* note2;
		file >> aux;
		int select = 0;

		if (aux >= 0) {
			switch (aux) {
			case 0:
				select = -1;
				note = nullptr;
				note2 = nullptr;
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_LEFT, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_UP, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_DPAD_DOWN, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			case 5:
				note = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->leftNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->leftNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			default:
				break;
			}
			level->levelArrows_.push_back(note);
			level->levelArrows2_.push_back(note2);

			if (aux != 0) noteAmount++;
		}
	}

	aux = 0;

	while (aux >= 0) {
		Note* note;
		int select = 0;
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
				note = new Note(SDL_CONTROLLER_BUTTON_A, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_A, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_B, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_B, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_X, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_X, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_Y, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_Y, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
				break;
			case 5:
				note = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->rightNotesVector, noteVel, level->getGameManager()->getP1Controller());
				note2 = new Note(SDL_CONTROLLER_BUTTON_INVALID, gm, noteSize_, noteSize_, level->rightNotesVector2, noteVel, level->getGameManager()->getP2Controller());
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

