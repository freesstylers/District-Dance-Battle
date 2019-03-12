#pragma once
#include "Playstate.h"

//Constantes
class PlayState2P : public PlayState //Clase para las batallas y jugabilidad b�sica, render lo hereda de GameState, mantiene update y handleEvent independientes
{
protected:

	LevelInputManager* lip;

	int pointSize = 80;	
	int noteSize = 50;	
	int pointOffset = 100;	
	int initialNoteHeight = 10;	

public:

	PlayState2P(GameManager* g);
	void newGame(); 
	~PlayState2P();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
	std::list<Note*> screenArrows_; 
	std::list<Note*> screenButtons_;
	Point* leftPoint2; 
	Point* rightPoint2;
	Feedback* feedbackLeft2;
	Feedback* feedbackRight2;
	Squares* leftSquare2;
	Squares* rightSquare2;
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;

protected:
	void deleteAll(); 
	void generateArrows();
	void generateButtons();

};