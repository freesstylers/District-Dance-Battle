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
