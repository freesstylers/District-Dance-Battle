#include "pch.h"


LevelEvent::LevelEvent(string timeStamp) : Event(timeStamp, LEVEL_EVENT) {

}

void LevelEvent::setLevel(int level) {
	level_ = level;
}
void LevelEvent::setScore(int score) {
	score_ = score;
}

string LevelEvent::toJson()
{
	Event::toJson();
	j["level"] = level_;
	j["score"] = score_;
	
	return j.dump(4);
}
