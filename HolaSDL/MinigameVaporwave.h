#pragma once
#include "MiniGame.h"

class PlayState;
class GameManager;

class MinigameVaporwave: public MiniGame
{
protected:
	int noteAmount = 15;
	int maxNotes = noteAmount;

public:
	bool getFailed() { return failed; };
	MinigameVaporwave(GameManager* g, PlayState* p);
	~MinigameVaporwave() { delete timer; };
	std::list<Note*> levelButtons_;
	//std::list<Note*> screenButtons_;
	void generateButtons();
	void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual void createList();
	virtual void deleteList();

};

