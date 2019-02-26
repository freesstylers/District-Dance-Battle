#pragma once
#include "GameState.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "GameObject.h"
#include "Timer.h"
#include "Flechas.h"
#include "Point.h"
#include "BeatHandeler.h"
#include "LevelInputManager.h"
#include "QTEManager.h"
#include "Perico.h"
#include "Level.h"

//Constantes

class PlayState : public GameState //Clase para las batallas y jugabilidad básica, render lo hereda de GameState, mantiene update y handleEvent independientes
{
protected:

	string level;
	int songLength;
	int maxPoints;
	int currentPoints;
	Timer* timer;
	BeatHandeler* bh;
	LevelInputManager* lip;
	Vector2D velFlechas;
	QTEManager* qteman;
	Perico* perico;
	Level* nivel;

public:
	PlayState(GameManager* g); //Crea estado (tal vez para niveles de dificultad con un int o bool)
	void newGame(); //Inicializa objetos
	~PlayState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time);
	Vector2D asignaVel(double time);
	void playSong(int song);
	std::list<Flechas*> flechasPantalla_; //La otra lista (Actors) se hereda de GameState
	std::list<Flechas*> botonesPantalla_;

	std::list<Flechas*> flechasNivel_;
	std::list<Flechas*> botonesNivel_;
	Point* punto; //Pulsador
	Point* puntobot;

	Vector2D posFlechaInicial = Vector2D(310, 10);
	Vector2D posBotonInicial = Vector2D(510, 10);

protected:
	void DeleteAll(); //Para borrado de objetos, por aquello de no dejar basura
	int getPoints();
	void changePoints(int data);
	void generateFlechas();
	void generateBotones();

};
