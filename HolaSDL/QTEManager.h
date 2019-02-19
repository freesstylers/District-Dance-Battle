#pragma once
#include "Timer.h"
#include "GameObject.h"
#include "Flechas.h"

class SDLGame;

class QTEManager
{
public:

	QTEManager(SDLGame* l);
	~QTEManager();

	void update(Uint32 time);
	void handleInput(Uint32 time, const SDL_Event& event);
	void render(Uint32 time);
	Flechas* getFlecha() { return flecha; }

private:

	Timer* timer;
	bool keyup = true;
	SDLGame* level;
	Flechas* flecha = nullptr;

};

