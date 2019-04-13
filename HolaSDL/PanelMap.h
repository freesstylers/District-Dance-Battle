#pragma once
#include "EmptyObject.h"

class GameManager;

class PanelMap
{
public:
	PanelMap();
	PanelMap(GameManager* manager, Vector2D panelPos, int photo, int difficulty, string name, int level);
	virtual ~PanelMap();
	void render(Uint32 time, bool beatHandler);
	void renderLetters(Uint32 time, bool beatHandler);
	void reset();
	void prevSwitch();
	void nextSwitch();
	void selectButton();
	int index = 0;
	int lvl_;
	bool selected = false;
private:
	GameManager * manager_;

	string types[6] = { "Tutorial", "VaporWave", "HipHop", "??????" , "A" , "A" };

	EmptyObject switches[3];
	EmptyObject fondo_;
	EmptyObject photo_;
	EmptyObject star_;

	vector<string> descripcion;

	int height = 300;
	int width = 200;
	int difficulty_;
	
	int numLineas = 0;

	bool oneP_ = true;
	bool hardMode_ = false;
	bool difActive = false;

	string name_;
	string description_;
};

