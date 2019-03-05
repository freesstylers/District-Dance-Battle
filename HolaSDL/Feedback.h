#pragma once
#include "GameObject.h"
#include "Timer.h"

class Feedback : public GameObject
{
private:
	virtual void changeAnimation(int animationTag);

	int lastUpdate = 0;	//time since the object was last updated, resets when queueAnimationChange is called

	int feedbackDecayTime = 3500;	//maximum time the object is allowed to stay on screen without changing (in ms)

public:
	Feedback(SDLGame* game, double width, double height, Vector2D pos);
	virtual ~Feedback();
	virtual void render(Uint32 time, bool beatSync);
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; }

	virtual void queueAnimationChange(int animationTag);
};

