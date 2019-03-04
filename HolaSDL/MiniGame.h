#pragma once
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "GameObject.h"
#include "Timer.h"
#include "Flechas.h"

using namespace std;

class GameManager;
class MiniGame
{
protected:
	string level;
	std::list<Flechas*> flechas;
	GameManager* manager;

public:
	MiniGame(GameManager* g);
	~MiniGame();
	list<Flechas*> getList() { return flechas; };

};