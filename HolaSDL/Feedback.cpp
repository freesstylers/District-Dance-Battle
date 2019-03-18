#include "Feedback.h"


Feedback::Feedback()
{
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Blank);

	isAnimationSyncedToMusic = true;

	active_ = false;
}

Feedback::Feedback(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Blank);

	isAnimationSyncedToMusic = true;

	active_ = false;
}

void Feedback::update(Uint32 time)
{
	if (lastUpdate == 0)
		lastUpdate = time;

	position_ = position_ + velocity_;

	if (time - lastUpdate >= feedbackDecayTime && active_)
		setActive(false);
}

Feedback::~Feedback()
{
}

void Feedback::forceAnimationChange(int animationTag)
{
	GameObject::forceAnimationChange(animationTag);

	lastUpdate = 0;
}