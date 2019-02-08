#pragma once

#include "GameObject.h"
#include "Egg.h"

/*
 *
 */
class EggsShooter: public GameObject {
public:
	EggsShooter(SDLGame* game);
	virtual ~EggsShooter();
	// abstract methods to be implemented in sub-classes
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual void addEgg(Vector2D pos, Vector2D vel, Vector2D acc);
private:
	Egg* getUnusedEgg();
	static int const MAX_EGGS=20;
	Egg eggs_[MAX_EGGS];
};

