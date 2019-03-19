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
	DialogState(GameManager* g, string txt, int numctrl);
	~DialogState();
	void init();
	virtual void update(Uint32 time) {};
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
protected:
	SDL_GameController* controller = NULL;
	struct Dialog
	{
		string text;
		string box;
	};
	bool keyup = true;
	list<Dialog> dialogo;
	list <GameObject*> sprites;
	map<string, GameObject*> box;
	GameObject* actualBox;
	string actualText;
	string archivo;
};

