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
#include "MiniGame.h"
#include "BarraPuntos.h"
#include "Feedback.h"
#include "EmptyObject.h"
#include "Squares.h"
#include "Level.h"
#include "Background.h"
#include "TimerNoSingleton.h"

//Constantes
class PlayState : public GameState //Clase para las batallas y jugabilidad b�sica, render lo hereda de GameState, mantiene update y handleEvent independientes
{
protected:

	string level;
	int currentPoints;
	bool effect = true;

	Timer* timer;
	LevelInputManager* lip;
	int probqte;
	int bpm;
	double tiempo;
	bool miniActive = true;
	TimerNoSingleton* minigameController;


	//Se usa para cuando al volver de un minijuego se sepa si es la primera flecha
	bool primeraFlecha = true;



	Vector2D velFlechas;
	QTEManager* qteman;
	MiniGame* minigame;
	Perico* perico;
	Feedback* a;
	EmptyObject* effectVaporWave;
	Level* nivel;

	BarrasHUD* indicador; //nota indicadora
	FondoBarra* spriteBarra; //barra tiempo
	BarraPuntos* barraPuntos; //barra puntuacion

	bool beatSignal = false;	//bool usado para avisar de que se avance la animaci�n seg�n el ritmo de la canci�n
	int animationFramesPerBeat = 2;	//int que determina cu�ntas frames de animaci�n van entre cada beat

	int pointSize = 80;	//tama�o del pulsador/punto
	int noteSize = 50;	//tama�o de nota 
	int pointOffset = 100;	//offset entre las barras de notas y el centro de la pantalla
	int initialNoteHeight = 10;	//altura a la cual se generan las notas en pantalla
	Feedback* feedback1;
	Feedback* feedback2;

public:
	BeatHandeler* bh;
	PlayState(GameManager* g); //Crea estado (tal vez para niveles de dificultad con un int o bool)
	void newGame(); //Inicializa objetos
	~PlayState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
	void playSong(int song);
	Vector2D asignaVel(double time);
	std::list<Flechas*> flechasNivel_;
	std::list<Flechas*> botonesNivel_;
	std::list<Flechas*> flechasPantalla_; //La otra lista (Actors) se hereda de GameState
	std::list<Flechas*> botonesPantalla_;
	Point* leftPoint; //Pulsador
	Point* rightPoint;
	Feedback* feedbackLeft;
	Feedback* feedbackRight;
	Squares* leftSquare;
	Squares* rightSquare;
	Background* bg;
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;
	MiniGame* getMinigame() { return minigame; }
	GameManager* getGameManager() { return manager; }

protected:
	void DeleteAll(); //Para borrado de objetos, por aquello de no dejar basura
	int getPoints();
	void changePoints(int data);
	void generateFlechas();
	void generateBotones();

};