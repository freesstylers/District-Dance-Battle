#pragma once
#include "GameObject.h"
class BarrasHUD
{
protected:
	bool findeNivel;
public:

	BarrasHUD(SDLGame* game);
	int Avanza(int &valorBarra);
	bool bolAvanza(int &valueBarra);
	virtual void render(Uint32 time);
private:

	~BarrasHUD();
};

