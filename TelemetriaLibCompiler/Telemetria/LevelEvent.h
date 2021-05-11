#pragma once
#include "Event.h"
class LevelEvent: public Event
{
public:
	LevelEvent(float timeStamp);

	void setLevel(int level);
	void setScore(int score);

	virtual string toJson();


protected:

	int level_;
	int score_;


};

