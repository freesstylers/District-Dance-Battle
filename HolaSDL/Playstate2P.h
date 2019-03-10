#pragma once
#include "Playstate.h"

//Constantes
class PlayState2P : public PlayState //Clase para las batallas y jugabilidad b�sica, render lo hereda de GameState, mantiene update y handleEvent independientes
{
protected:

	LevelInputManager* lip;

	int pointSize = 80;	//tama�o del pulsador/punto
	int noteSize = 50;	//tama�o de nota 
	int pointOffset = 100;	//offset entre las barras de notas y el centro de la pantalla
	int initialNoteHeight = 10;	//altura a la cual se generan las notas en pantalla

public:

	PlayState2P(GameManager* g); //Crea estado (tal vez para niveles de dificultad con un int o bool)
	void newGame(); //Inicializa objetos
	~PlayState2P();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
	std::list<Flechas*> flechasPantalla_; //La otra lista (Actors) se hereda de GameState
	std::list<Flechas*> botonesPantalla_;
	Point* leftPoint2; //Pulsador
	Point* rightPoint2;
	Feedback* feedbackLeft2;
	Feedback* feedbackRight2;
	Squares* leftSquare2;
	Squares* rightSquare2;
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;

protected:
	void DeleteAll(); //Para borrado de objetos, por aquello de no dejar basura
	void generateFlechas();
	void generateBotones();

};