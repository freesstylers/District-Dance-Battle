#pragma once
#include "Timer.h"
#include "GameObject.h"
#include "Flechas.h"

class PlayState;

class QTEManager
{
public:

	QTEManager(PlayState* l, int proba);
	~QTEManager();

	void update(Uint32 time);
	void handleInput(Uint32 time, const SDL_Event& event);
	void render(Uint32 time);
	Flechas* getFlecha() { return flecha; }

private:
	bool activo = false;
	int prob;
	Timer* timer;
	bool keyup = true;
	PlayState* level;
	Flechas* flecha = nullptr;

};