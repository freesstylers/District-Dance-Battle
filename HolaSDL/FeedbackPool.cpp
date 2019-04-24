#include "FeedbackPool.h"


FeedbackPool::FeedbackPool(SDLGame * game, double width, double height, Vector2D pos) : GameObjectPool<Feedback, 30>(game)
{
	initialPos = pos;

	for (auto feedback : getAllObjects()) {

		Vector2D vel = Vector2D(0, - feedbackMaxHeight / feedbackDecayTime);

		feedback->setWidth(width);
		feedback->setHeight(height);
		feedback->setPosition(pos);
		feedback->setVelocity(vel);
		feedback->setDecayTime(feedbackDecayTime);
	}
}

FeedbackPool::~FeedbackPool()
{
}

void FeedbackPool::addFeedback(int animation)
{
	Feedback* f = getUnusedObject();

	f->setPosition(initialPos);
	f->forceAnimationChange(animation);
	f->setAlpha(255);
}
void FeedbackPool::updateResolution(double wScale, double hScale) {
/*

	for (auto feedback : getAllObjects()) {

		Vector2D pos = feedback->getPosition();

		pos.setX(pos.getX() * wScale);

		pos.setY(pos.getY() * hScale);

		Vector2D vel = Vector2D(0, -feedbackMaxHeight * hScale / feedbackDecayTime);

		feedback->setWidth(feedback->getWidth() * wScale);
		feedback->setHeight(feedback->getHeight() * hScale);
		feedback->setPosition(pos);
		feedback->setVelocity(vel);
	}*/
}