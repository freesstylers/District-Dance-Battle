#include "pch.h"
using namespace tinyxml2;

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

string LevelEvent::toXML()
{
	Event::toXML();

	XMLElement* level = xml_.NewElement("level");
	level->SetText(level_);

	XMLElement* score = xml_.NewElement("score");
	score->SetText(score_);

	XMLElement* max_combo_count = xml_.NewElement("max_combo_count");
	max_combo_count->SetText(max_combo_count_);

	XMLElement* combo_time = xml_.NewElement("combo_time");
	combo_time->SetText(combo_time_);

	XMLElement* input_type = xml_.NewElement("input_type");
	input_type->SetText(input_enum_str[input_type_]);


	eventRoot_->InsertEndChild(level);
	eventRoot_->InsertEndChild(score);
	eventRoot_->InsertEndChild(max_combo_count);
	eventRoot_->InsertEndChild(combo_time);
	eventRoot_->InsertEndChild(input_type);

	XMLPrinter printer_;

	xml_.Print(&printer_);
	return printer_.CStr();
}

string LevelEvent::toCSV()
{
	string csv = Event::toCSV();
	csv += ", ";

	csv += std::to_string(level_);
	csv += ", ";

	csv += ", ";

	csv += ", ";

	csv += ", ";

	csv += ", ";

	csv += std::to_string(score_);
	csv += ", ";

	csv += std::to_string(max_combo_count_);
	csv += ", ";

	csv += std::to_string(combo_time_);
	csv += ", ";

	csv += input_enum_str[input_type_];

	return csv;
}
