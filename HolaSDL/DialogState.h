#pragma once
#include "GameState.h"
#include <vector>
#include <list>
#include <string>
#include <map>
#include <math.h>

class DialogState: public GameState
{
public:
	DialogState(GameManager* g, string txt);
	~DialogState();
	void init();
	virtual void update(Uint32 time) {};
	virtual bool handleEvent(Uint32 time, SDL_Event e) { return true; };
	virtual void render(Uint32 time, bool beatSync = false) {};
protected:
	struct Dialog
	{
		string text;
		string box;
	};
	list<Dialog> dialogo;
	list <GameObject*> sprites;
	map<string, GameObject*> box;
	GameObject* actualBox;
	string actualText;
	string archivo;
};

