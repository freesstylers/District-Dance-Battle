#pragma once
#include "MiniGame.h"
#include "EmptyObject.h"

class TutorialMinigame : public MiniGame
{
protected:
	Texture * textureButton;
	EmptyObject * cuadroTutorial;

	int numDialog = 0;

public:
	TutorialMinigame(GameManager* g, PlayState* p);
	~TutorialMinigame();
	void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event e);
	void changeCuadroTutorial();


	void resume();
	void pause();
};



/*
class MinigameVaporwave : public MiniGame
{


public:
	MinigameVaporwave(GameManager* g, PlayState* p);

	void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event e);

	void generateButtons();
	bool getFailed() { return failed; };
	bool getEnd() { return end; }

	virtual void createList();
	virtual void deleteList();

	virtual void updateResolution(double wScale, double hScale);
};*/
