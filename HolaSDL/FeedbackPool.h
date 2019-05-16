#pragma once
#include "GameObjectPool.h"
#include "Feedback.h"
#include "checkML.h"

//A pool of Feedback objects used to display a large amount on-screen

class FeedbackPool :
	public GameObjectPool<Feedback, 30>
{
private:

	int feedbackDecayTime = 35;		//time (in ms) the object will take to disappear
	int feedbackMaxHeight = 100;	//maximum RELATIVE height the feedback will reach before vanishing

	Vector2D initialPos;

public:
	FeedbackPool(SDLGame* game, double width, double height, Vector2D pos);
	virtual ~FeedbackPool();

	virtual void addFeedback(int animation);
};

