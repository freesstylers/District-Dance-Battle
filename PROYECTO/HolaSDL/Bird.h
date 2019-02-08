#pragma once

#include "EggsShooter.h"
#include "GameObject.h"

/*
 *
 */
class Bird: public GameObject {
public:
	Bird(SDLGame* game, EggsShooter* eggsShooter);
	virtual ~Bird();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:

	Texture* birdTexture_;

	// information on the texture ...
	int frames_;
	int currFrame_;
	int cols_;
	int rows_;
	int frameWidth_;
	int frameHeight_;

	Uint32 lastTimeUpdated_;  // last time we update a frame
	Uint32 freq_; // the frequency of updating frames

	EggsShooter* eggsShooter_; // used to throw eggs ...
};

