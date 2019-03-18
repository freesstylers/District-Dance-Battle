#pragma once
#include "GameObjectPool.h"
#include "Feedback.h"

class FeedbackPool :
	public GameObjectPool<Feedback, 30>

{
public:
	FeedbackPool(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel);
	~FeedbackPool();

	void showFeedback(int type);
};

