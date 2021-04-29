#pragma once
#include "Event.h"
class LevelEvent: public Event
{
public:
	LevelEvent(float timeStamp) : Event(timeStamp) {

	}

	void setLevel(int level) {
		level_ = level;
	}
	void setScore(int score) {
		score_ = score;
	}


protected:

	int level_;
	int score_;


};

