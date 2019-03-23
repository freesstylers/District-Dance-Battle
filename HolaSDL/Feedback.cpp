#include "Feedback.h"

Feedback::Feedback() : GameObject() {


}
Feedback::Feedback(SDLGame* game, double width, double height, Vector2D pos) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));

	init();
}

void Feedback::init() {
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Blank);

	isAnimationSyncedToMusic = true;

	active_ = false;
}

void Feedback::update(Uint32 time)
{
	if (active_) {
		if (lastUpdate == 0)
			lastUpdate = time;

		position_ = position_ + velocity_;

		if (time - lastUpdate >= feedbackDecayTime) {
			if (getAlpha() == 0)
				setActive(false);
			else
				changeAlpha(alphaUpdate);
		}
	}
}

Feedback::~Feedback()
{
}

void Feedback::forceAnimationChange(int animationTag)
{
	GameObject::forceAnimationChange(animationTag);

	lastUpdate = 0;
}