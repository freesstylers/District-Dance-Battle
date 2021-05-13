#pragma once
#include "Event.h"
class LevelEvent: public Event
{
public:
	LevelEvent(string timeStamp);

	void setLevel(int level);
	void setScore(int score);

	virtual string toJson();


protected:

	int level_;
	int score_;


};

