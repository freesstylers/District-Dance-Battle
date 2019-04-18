#include "RedEffect.h"

RedEffect::RedEffect() : GameObject() {

	setWidth(800);
	setHeight(600);
	setPosition(Vector2D(0, 0));
	setVelocity(Vector2D(0, 0));

	init();

}
RedEffect::RedEffect(SDLGame* game, double width, double height, Vector2D pos) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));

	init();
}

void RedEffect::init() {
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::RedAura);

	isAnimationSyncedToMusic = true;

	active_ = false;
}

void RedEffect::update(Uint32 time)
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

RedEffect::~RedEffect()
{
}

void RedEffect::forceAnimationChange(int animationTag)
{
	GameObject::forceAnimationChange(animationTag);

	lastUpdate = 0;
}