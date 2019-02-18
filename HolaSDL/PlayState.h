#pragma once
#include "GameState.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include "GameObject.h"
#include "Timer.h"
#include "Flechas.h"
#include "Point.h"
#include "BeatHandeler.h"

//Constantes

class PlayState : public GameState //Clase para las batallas y jugabilidad básica, render lo hereda de GameState, mantiene update y handleEvent independientes
{
protected:
	
	int songLength;
	int maxPoints;
	int currentPoints;
	std::list<Flechas*> flechasPantalla_; //La otra lista (Actors) se hereda de GameState
	std::list<Flechas*> flechasNivel_;
	Timer* timer;
	Point* punto; //Pulsador
	BeatHandeler* bh;
	
public:
	PlayState(GameManager* g); //Crea estado (tal vez para niveles de dificultad con un int o bool)
	void newGame(); //Inicializa objetos
	~PlayState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time);

protected:
	void DeleteAll(); //Para borrado de objetos, por aquello de no dejar basura
	int getPoints();
	void changePoints(int data);
	void generate();
};

