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
	bool effect = true;

	Timer* timer;
	LevelInputManager* lip;
	int probqte;
	bool miniActive = false;
	TimerNoSingleton* minigameController;


	//Se usa para cuando al volver de un minijuego se sepa si es la primera flecha
	bool primeraFlecha = true;



	Vector2D velFlechas;
	QTEManager* qteman;
	MiniGame* minigame;
	Perico* perico;
	Perico* robot;
	EmptyObject* effectVaporWave;
	Level* nivel;

	BarrasHUD* indicador; //nota indicadora
	FondoBarra* spriteBarra; //barra tiempo

	bool beatSignal = false;	//bool usado para avisar de que se avance la animaci�n seg�n el ritmo de la canci�n
	bool animationMiniGame = false;
	int animationFramesPerBeat = 2;	//int que determina cu�ntas frames de animaci�n van entre cada beat

	int pointSize = 80;	//tama�o del pulsador/punto
	int noteBarWidth = pointSize +33;
	int noteSize = 50;	//tama�o de nota 
	int pointOffset = 70;	//offset entre las barras de notas y el centro de la pantalla
	int initialNoteHeight = 70;	//altura a la cual se generan las notas en pantalla
	Feedback* feedback1;
	Feedback* feedback2;

	int maxScore = 100000;
	int currentScore = 0;
	int maxNoteValue = 0;

public:
	BeatHandeler* bh;
	BarraPuntos* barraPuntos; //barra puntuacion
	PlayState(GameManager* g); //Crea estado (tal vez para niveles de dificultad con un int o bool)
	void newGame(); //Inicializa objetos
	~PlayState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
	void playSong(int song);
	void showError();
	Vector2D asignaVel(double time);
	std::list<Flechas*> flechasNivel_;
	std::list<Flechas*> botonesNivel_;
	std::list<Flechas*> flechasPantalla_; //La otra lista (Actors) se hereda de GameState
	std::list<Flechas*> botonesPantalla_;
	Point* leftPoint; //Pulsador
	Point* rightPoint;
	Feedback* feedbackLeft;
	Feedback* feedbackRight;
	Squares* leftNoteBar;
	Squares* rightNoteBar;
	Background* bg;
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;
	MiniGame* getMinigame() { return minigame; }
	GameManager* getGameManager() { return manager; }

	double msDiff = 0.0;  //Son los milisegundos que  hay de diferencia entre el beat que queremos y cuando realmente sale

	void updateScore(int accuracy) { currentScore += maxNoteValue * (1 / accuracy); }

protected:
	void DeleteAll(); //Para borrado de objetos, por aquello de no dejar basura
	int getScore();
	void generateFlechas();
	void generateBotones();

	void songOver();
private:

};