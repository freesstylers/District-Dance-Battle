#pragma once
#include "GameState.h"
#include <vector>
#include <list>
#include <string>
#include <map>
#include <math.h>
#include "TextObject.h"
#include "checkML.h"
#include "TimerNoSingleton.h"
#include "TextBox.h"

//Esta es la clase usada como estado de juego para los diálogos

class DialogState: public GameState
{
public:
	DialogState(GameManager* g, int txt, int numctrl, bool oneP, bool difficulty, int prevMaxScoreE, int prevMaxScoreH); //Entra el entero del nivel para cargar el dialog que toque
	~DialogState();
	void init();
	virtual void update(Uint32 time) ;
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatsync = false);
protected:
	SDL_GameController* controller = NULL;
	int prevMaxScoreE_;
	int prevMaxScoreH_;

	struct Dialog
	{
		string text;
		string box;
	};

	
	//Los nombres de todos los archivos de diálogo para poder llamarlos.
	string levels[18] = { "Intro1", "Vapor1", "HipHop1", "Papito1", "Corpselillo1", "Onilecram1", "Intro2", "Intro2", "VaporW", "VaporL", "HipHopW", "HipHopL", "PapitoW", "PapitoL", "CorpselilloW", "CorpselilloL", "OnilecramW", "OnilecramL" }; 																									
	
	bool keyup = true;
	bool oneP_;
	bool hardMode_;
	list<Dialog> dialogo;
	list<TextBox*> textBoxes;

	//Diccionario que contiente cada textbox con su diálogo correspondiente.
	map<string, GameObject*> box;
	GameObject* actualBox;
	TextObject* text;
	TextObject* text2;
	TextBox* textBox;
	TimerNoSingleton* timer;
	double animationFramesPerBeat = 2;
	bool beatSignal = false;
	int nlevel;
	bool end = false;
	bool endlevel = false;
	string archivo;

	void updateText();
};

