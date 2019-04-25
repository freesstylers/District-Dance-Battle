#pragma once
#include "GameState.h"
#include "Button.h"
#include "Character.h"
#include "PlayState.h"
#include "TextObject.h"

class EndState :
	public GameState
{
public:
	
	EndState(GameManager* g, int actualScore, int maxScore, int percentage, int lvl, bool isSingleplayer, int actualScore2 = 0);
	virtual ~EndState();
	static void backToMenu(GameManager* gameManager);
	static void exit_(GameManager* gameManager);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatHandler);
	void renderLetters(Uint32 time, bool beatHandler);
	bool passed;

private:
	TextObject* points;
	TextObject* points2;
	TextObject* tooltip;
	string types[6] = { "Tutorial", "VaporWave", "HipHop", "??????" , "A" , "A" };
	int index = 0;
	int min = 0;
	int max = 1;
	int level;
	int punt;

	GameManager* gameManager;
	SDL_GameController* controller = NULL;
	void nextButton();
	void backButton();
	string puntos = "Puntuacion: ";
	string val = "Valoracion: ";
	
	string makeScoreBetter(int score);

};

