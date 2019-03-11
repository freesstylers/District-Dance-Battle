#include "Feedback.h"


Feedback::Feedback(SDLGame* game, double width, double height, Vector2D pos) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));


	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Blank);

	framesPerSecond = 4;
	//isAnimationSyncedToMusic = true;

	active_ = false;
}

void Feedback::update(Uint32 time)
{
	if (lastUpdate == 0)
		lastUpdate = time;

	if (time - lastUpdate >= feedbackDecayTime && active_) {
		setActive(false);
	}
}
Feedback::~Feedback()
{
}

void Feedback::queueAnimationChange(int animationTag, bool waitForAnimationEnd)
{
	GameObject::queueAnimationChange(animationTag, false);

	lastUpdate = 0;
}