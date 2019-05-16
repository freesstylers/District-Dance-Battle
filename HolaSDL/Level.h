#pragma once
#include <string>
#include "checkML.h"
#include"Vector2D.h"
#include"SRandBasedGenerator.h"


using namespace std;

//this class manages the loading of levels from their respective files

class PlayState;
class SDLGame;

class Level
{
public:
	Level(PlayState* l, SDLGame* gam,string n, int noteSize);
	~Level();

	void playSong();

	void init(bool hardmode);

	int bpm;
	int probqte;
	double songLength;
	int song;
	int maxScore;
	int noteAmount = 0;
	int noteSize_;
	SRandBasedGenerator random;

protected:
	string name;
	Vector2D noteVel;

	PlayState* level;
	SDLGame* gm;
};

