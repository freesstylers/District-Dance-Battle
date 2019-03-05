#include "Feedback.h"


Feedback::Feedback(SDLGame* game, double width, double height, Vector2D pos) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));


	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::FeedbackGood);

	framesPerSecond = 4;
	isAnimationSyncedToMusic = true;

	isRenderActive = false;
}

void Feedback::render(Uint32 time, bool beatSync)
{
	if (queuedAnimations.size() > 0) {
		changeAnimation(queuedAnimations.front());
	}

	if (isRenderActive)
	{
		animation.texture_->render(getRect(), getFrameRect());


		if ((!isAnimationSyncedToMusic && (time - lastRender) >= (1000 / framesPerSecond)) || (isAnimationSyncedToMusic && beatSync)) {	//animations update only when a certain time has passed OR when the "beatSync" signal is true
			animation.currentFrame = animation.currentFrame + 1;

			if (animation.currentFrame == animation.totalFrames) {
				animation.currentFrame = 0;
			}

			lastRender = time;
		}
	}
}

Feedback::~Feedback()
{
}

void Feedback::changeAnimation(int animationTag)
{
	int currentFrame = animation.currentFrame;

	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(animationTag);

	queuedAnimations.pop();

	animation.currentFrame = currentFrame;
}