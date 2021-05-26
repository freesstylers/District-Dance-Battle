#include "pch.h"


LevelEvent::LevelEvent(string timeStamp) : Event(timeStamp, LEVEL_EVENT) {
	level_ = -1;
	score_ = -1;
	max_combo_count_ = -1;
	combo_time_ = -1;
	input_type_ = KEYBOARD_INPUT;
}

void LevelEvent::setLevel(int level) {
	level_ = level;
}
void LevelEvent::setScore(int score) {
	score_ = score;
}

void LevelEvent::setMaxComboCount(int maxCombo){
	max_combo_count_ = maxCombo;
}

void LevelEvent::setComboTime(float comboTime){
	combo_time_ = comboTime;
}

void LevelEvent::setInputType(InputType input){
	input_type_ = input;
}

string LevelEvent::toJson(){
	Event::toJson();
	j["level"] = level_;
	j["score"] = score_;
	j["max_combo_count"] = max_combo_count_;
	j["combo_time"] = combo_time_;
	j["input_type"] = input_enum_str[input_type_];
	nlohmann::json aux2 = j;
	return aux2.dump(4);
}
