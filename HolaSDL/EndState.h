#pragma once
#include "GameState.h"
#include "Button.h"
#include "Character.h"
#include "PlayState.h"

class EndState :
	public GameState
{
public:
	//EndState();
	EndState(GameManager* g, int actualScore, int maxScore, int percentage,int lvl);
	virtual ~EndState();
	static void backToMenu(GameManager* gameManager);
	static void exit_(GameManager* gameManager);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	//virtual void update(Uint32 time);
	virtual void render(Uint32 time, bool beatHandler);
	void renderLetters(Uint32 time, bool beatHandler);

	/*std::list<EmptyObject*>::iterator firstButton;
	std::list<EmptyObject*>::iterator selectedButton;*/
	pair<EmptyObject, bool>buttons[2];
private:
	string types[6] = { "Tutorial", "VaporWave", "HipHop", "??????" , "A" , "A" };
	//MapState* map;
	//void createButtons();
	int index=0 ;
	int min = 0;
	int max = 1;
	int level;
	int punt;
	GameManager* gameManager;
	SDL_GameController* controller = NULL;
	void nextButton();
	void backButton();
	string puntos = "Puntuacion: " + punt;
	string val = "Valoracion: ";
};

