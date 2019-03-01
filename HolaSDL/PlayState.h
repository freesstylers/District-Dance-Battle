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
#include "BarrasHUD.h"
#include "FondoBarra.h"
#include "BarraPuntos.h"

//Constantes

class PlayState : public GameState //Clase para las batallas y jugabilidad básica, render lo hereda de GameState, mantiene update y handleEvent independientes
{
protected:

	string level;
	int songLength;
	int maxPoints;
	int currentPoints;
	int probqte;
	int bpm;
	double tiempo;
	std::list<Flechas*> flechasNivel_;
	std::list<Flechas*> botonesNivel_;
	Timer* timer;
	BeatHandeler* bh;
	LevelInputManager* lip;
	Vector2D velFlechas;
	QTEManager* qteman;
	Perico* perico;

	BarrasHUD* indicador; //nota indicadora
	FondoBarra* spriteBarra; //barra tiempo
	BarraPuntos* barraPuntos; //barra puntuacion

	bool beatSignal = false;	//bool usado para avisar de que se avance la animación según el ritmo de la canción
	int animationFramesPerBeat = 2;	//int que determina cuántas frames de animación van entre cada beat

public:
	PlayState(GameManager* g); //Crea estado (tal vez para niveles de dificultad con un int o bool)
	void newGame(); //Inicializa objetos
	~PlayState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
	std::list<Flechas*> flechasPantalla_; //La otra lista (Actors) se hereda de GameState
	std::list<Flechas*> botonesPantalla_;
	Point* punto; //Pulsador
	Point* puntobot;

protected:
	void DeleteAll(); //Para borrado de objetos, por aquello de no dejar basura
	int getPoints();
	void changePoints(int data);
	void generateFlechas();
	void generateBotones();
	Vector2D asignaVel(double time);
	Vector2D posFlechaInicial = Vector2D(310, 10);
	Vector2D posBotonInicial = Vector2D(510, 10);

};
