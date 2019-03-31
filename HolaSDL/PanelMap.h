#pragma once
#include "EmptyObject.h"
#include "GameManager.h"

class PanelMap
{
public:
	PanelMap();
	PanelMap(GameManager* gm, Vector2D panelPos, int photo, string description, int difficulty, string name);
	virtual ~PanelMap();
	void render(Uint32 time, bool beatHandler);
	int index = 0;
private:
	//EmptyObject switches[3];
	EmptyObject fondo_;
	EmptyObject photo_;

	int height = 250;
	int width = 100;
	int difficulty_;

	bool oneP_ = true;
	bool facil_ = true;

	string name_;
};

