#pragma once
#include "Event.h"
class LevelEvent: public Event
{
public:
	LevelEvent(string timeStamp);

	void setLevel(int level);
	void setScore(int score);
	void setMaxComboCount(int maxCombo);
	void setComboTime(float comboTime);
	void setInputType(InputType input);

	virtual string toJson();
	virtual string toXML();


protected:
	LevelEvent(string timeStamp, EventType eventType):Event(timeStamp, eventType) {
		level_ = -1;
		score_ = -1;
		max_combo_count_ = -1;
		combo_time_ = -1;
		input_type_ = KEYBOARD_INPUT;
	};
	int level_;
	int score_;
	int max_combo_count_;
	float combo_time_;
	InputType input_type_;
};

