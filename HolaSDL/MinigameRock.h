#pragma once
#include "MiniGame.h"

class MinigameRock: public MiniGame
{
protected:
	int noteAmount = 1;
	int maxNotes = noteAmount;

public:
	MinigameRock(GameManager* g, PlayState* p);
	~MinigameRock();
	virtual void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event e);

	void generateButtons();
	bool getFailed() { return failed; };

	virtual void createList();
	virtual void deleteList();
};

