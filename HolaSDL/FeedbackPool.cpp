#include "FeedbackPool.h"



FeedbackPool::FeedbackPool(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel) : GameObjectPool<Feedback, 30>(game)
{
	for (auto f : getAllObjects()) {
		f->setWidth(width);
		f->setHeight(height);
		f->setPosition(pos);
		f->setVelocity(vel);
	}

}


FeedbackPool::~FeedbackPool()
{
}

void FeedbackPool::showFeedback(int type)
{
	Feedback* f = getUnusedObject();

	f->forceAnimationChange(type);
}
