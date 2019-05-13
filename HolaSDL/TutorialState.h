#pragma once
#include "PlayState.h"
#include "checkML.h"

class GameManager;

class TutorialState :
	public PlayState
{
private:
	double pauseAmount = 6;
	EmptyObject* tutorialBox;
	EmptyObject* tutoFiltro;

	int auxTime = 0;
	int numStops = 1;
	int tutorialBoxAnim = Resources::AButton1;
	bool isTutorialPaused = false;
	SDL_GameController* controller = NULL;

public:
	TutorialState(GameManager* g);
	~TutorialState();


	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual bool pauseTutorial();
	virtual void resumeTutorial(GameManager* g, unsigned int timePaused);

};

