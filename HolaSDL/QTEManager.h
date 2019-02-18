#pragma once

#include "GameObject.h"

class DemoGame;

class QTEManager
{
public:

	QTEManager(DemoGame* l);
	~QTEManager();

	void update(Uint32 time);
	void handleInput(Uint32 time, const SDL_Event& event);

private:

	void sendQTE();

	bool keyup = true;
	DemoGame* level;

};

