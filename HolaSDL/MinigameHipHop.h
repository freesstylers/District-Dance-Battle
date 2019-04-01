#pragma once
#include "MiniGame.h"
#include "Crosshair.h"

class MinigameHipHop : public MiniGame
{
public:
	MinigameHipHop(GameManager* g, PlayState* p);;
	~MinigameHipHop();
	virtual void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event e);
	void generateButtons();
	bool getFailed() { return failed; };

	virtual void createList();
	virtual void deleteList();
	virtual void resetMinigame();

protected:
	int noteAmount = 15;
	int maxNotes = noteAmount;
	Crosshair* mira;
};

