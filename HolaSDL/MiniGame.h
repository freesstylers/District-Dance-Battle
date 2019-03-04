#pragma once
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "GameObject.h"
#include "Timer.h"
#include "Flechas.h"

#include "LevelInputManager.h"


using namespace std;
class PLayState;
class GameManager;
class MiniGame
{
protected:
	SDL_GameController* controller = NULL;
	bool keyup = true;
	bool keyup2 = true;
	bool fallado = false;
	string level;
	std::list<Flechas*> botonesNivel_;
	std::list<Flechas*> botonesPantalla_;
	GameManager* manager;
	PlayState* playS;


public:
	MiniGame(GameManager* g, PlayState* p );
	~MiniGame();
	void generaBotones();
	void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	//list<Flechas*> getList() { return flechas; };

};