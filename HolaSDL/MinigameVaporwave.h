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
	void render(Uint32 time);
	virtual void update(Uint32 time);

	void generateButtons();
	bool getFailed() { return failed; };

	virtual void createList();
	virtual void deleteList();

};

