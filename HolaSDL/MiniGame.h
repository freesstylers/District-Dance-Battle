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
class PlayState;
class GameManager;
class LevelInputManager;
class MiniGame
{
protected:
	SDL_GameController* controller = NULL;
	bool keyup = true;
	bool keyup2 = true;
	bool fallado = false;
	string level;
	GameManager* manager;
	PlayState* playS;


public:
	MiniGame(GameManager* g, PlayState* p );
	~MiniGame();
	std::list<Flechas*> botonesNivel_;
	std::list<Flechas*> botonesPantalla_;
	void generaBotones();
	void render(Uint32 time);
	virtual void update(Uint32 time);

	//list<Flechas*> getList() { return flechas; };

};