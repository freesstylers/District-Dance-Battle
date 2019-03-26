#pragma once
#include "MiniGame.h"


class MinigameVaporwave: public MiniGame
{
protected:
	int noteAmount = 15;
	int maxNotes = noteAmount;

public:
	MinigameVaporwave(GameManager* g, PlayState* p);
	~MinigameVaporwave() { delete timer; };
	virtual void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event e);

	void generateButtons();
	bool getFailed() { return failed; };

	virtual void createList();
	virtual void deleteList();

};

