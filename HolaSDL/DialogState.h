#pragma once
#include "GameState.h"
#include <vector>
#include <list>
#include <string>
#include <map>
#include <math.h>
#include "TextObject.h"

class DialogState: public GameState
{
public:
	DialogState(GameManager* g, int txt, int numctrl, bool oneP, bool difficulty); //Entra el entero del nivel para cargar el dialog que toque
	~DialogState();
	void init();
	virtual void update(Uint32 time) {};
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatsync = false);
protected:
	SDL_GameController* controller = NULL;
	struct Dialog
	{
		string text;
		string box;
	};
	string levels[6] = { "Dialog0", "Vapor1", "HipHop1", "Papito", "Dialog4", "Dialog5" }; //El dialogo 0 es el del tutoria, de ahi hasta el dialogo del nivel 5
	bool keyup = true;
	bool oneP_;
	bool hardMode_;
	list<Dialog> dialogo;
	map<string, GameObject*> box;
	GameObject* actualBox;
	TextObject* text;
	TextObject* text2;
	int nlevel;
	bool end = false;
	bool endlevel = false;
	string archivo;

	void updateText();
};

