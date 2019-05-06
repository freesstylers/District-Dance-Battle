#pragma once
#include "MiniGame.h"
#include "checkML.h"

class MinigameVaporwave: public MiniGame
{
protected:
	Texture * textureButton;

public:
	MinigameVaporwave(GameManager* g, PlayState* p);
	~MinigameVaporwave() { delete timer; };
	void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event e);

	void generateButtons();
	bool getFailed() { return failed; };
	bool getEnd() { return end; }

	virtual void createList();
	virtual void deleteList();

	virtual void updateResolution(double wScale, double hScale);
};

