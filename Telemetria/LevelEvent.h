#pragma once
#include "Event.h"
class LevelEvent: public Event
{
public:
	LevelEvent(float timeStamp) : Event(timeStamp, LEVEL_EVENT) {

	}

	void setLevel(int level) {
		level_ = level;
	}
	void setScore(int score) {
		score_ = score;
	}

	virtual string toJson();


protected:

	int level_;
	int score_;


};

