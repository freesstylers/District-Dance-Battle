#pragma once

#include <string>

#include"Vector2D.h"

using namespace std;

class PlayState;

class Level
{
public:
	Level(PlayState* l, string n);
	~Level();

	void playSong();

	void init();

	int bpm;
	int probqte;
	int tiempo;
	int song;

protected:
	string name;
	Vector2D velFlechas;

	PlayState* level;


};

