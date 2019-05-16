#pragma once
#include "GameState.h"
#include <vector>
#include <list>
#include <string>
#include <map>
#include <math.h>
#include "TextObject.h"
#include "checkML.h"
#include "Timer.h"
#include "TextBox.h"

//State used to manage the game's dialogue

class DialogState: public GameState
{
public:
	DialogState(GameManager* g, int txt, int numctrl, bool oneP, bool difficulty, int prevMaxScoreE, int prevMaxScoreH); //input the level's int index to load it
	~DialogState();
	void init();
	virtual void update(Uint32 time) ;
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatsync = false);
protected:
	SDL_GameController* controller = NULL;
	int prevMaxScoreE_;
	int prevMaxScoreH_;

	//struct used to manage how the dialogue files are coded: first, the character's name, then what they say
	struct Dialog
	{
		string text;
		string box;
	};

	
	//These are the names of all the dialogue files
	string levels[18] = { "Intro1", "Vapor1", "Papito1", "HipHop1", "Corpselillo1", "Onilecram1", "Intro2", "Intro2", "VaporW", "VaporL", "PapitoW", "PapitoL", "HipHopW", "HipHopL","CorpselilloW", "CorpselilloL", "OnilecramW", "OnilecramL" };
	
	bool keyup = true;
	bool oneP_;
	bool hardMode_;
	list<Dialog> dialogo;
	list<TextBox*> textBoxes;

	//Map used to get each character's dialogue box
	map<string, GameObject*> box;

	GameObject* actualBox;
	TextObject* text;
	TextObject* text2;
	TextBox* textBox;
	Timer* timer;
	double animationFramesPerBeat = 2;
	bool beatSignal = false;
	int nlevel;
	bool end = false;
	bool endlevel = false;
	string archivo;

	void updateText();
};

