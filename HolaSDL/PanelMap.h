#pragma once
#include "EmptyObject.h"
#include "checkML.h"

class GameManager;

//Panel that appears when a Underground Stop is checked on MapState

class PanelMap
{
public:
	PanelMap();
	PanelMap(GameManager* manager, Vector2D panelPos, int photo, int difficulty, string name, int level);
	virtual ~PanelMap() {};
	void render(Uint32 time, bool beatHandler);
	void renderLetters(Uint32 time, bool beatHandler);
	void reset();
	void prevSwitch();
	void nextSwitch();
	void selectButton(SDL_Event e, SDL_GameController* cont);
	
	int index = 0;
	int lvl_;
	
	int scoreE_ = 0; //Previous High Scores
	int scoreH_ = 0;

	bool selected = false;
	bool difActive = false;
	bool hardModeCompleted = false;
private:
	GameManager * manager_;

	string types[6] = { "Tutorial", "VaporWave", "Reggetón", "HipHop", "Heavy Metal" , "Hardbass" };

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

	string name_;
	string description_;
};

