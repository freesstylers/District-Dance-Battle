
#pragma once
#include "GameObject.h"
#include "Timer.h"
#include "checkML.h"

class RedEffect : public GameObject
{
private:

	int lastUpdate = 0;	//time since the object was last updated, resets when queueAnimationChange is called

	int feedbackDecayTime = 0;	//time (in ms) the object will take to disappear

	int alphaUpdate = -10;

public:
	RedEffect();
	RedEffect(SDLGame* game, double width, double height, Vector2D pos);
	virtual ~RedEffect();
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; }
	virtual void init();

	virtual void forceAnimationChange(int animationTag);

	virtual void setDecayTime(int ms) { feedbackDecayTime = ms; }
};


