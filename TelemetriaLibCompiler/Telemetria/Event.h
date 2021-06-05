#pragma once
#include <string>
#include "json.hpp"
#include "tinyxml2.h"

using namespace std;

enum EventType {
	BASE_EVENT,
	LEVEL_EVENT,
	INPUT_EVENT,
	LOG_EVENT,
	DIALOG_SKIP_EVENT,
	LOST_LEVEL_EVENT
};

static const char* event_enum_str[]{
	"BASE_EVENT",
	"LEVEL_EVENT",
	"INPUT_EVENT",
	"LOG_EVENT",
	"DIALOG_SKIP_EVENT",
	"LOST_LEVEL_EVENT"
};

enum InputType: int {
	PS4_INPUT = 0,
	XBOX_INPUT = 1,
	ARROWS_INPUT = 2,
	KEYBOARD_INPUT = 3
};

static const char* input_enum_str[]{
	"PS4_INPUT",
	"XBOX_INPUT",
	"ARROWS_INPUT",
	"KEYBOARD_INPUT"
};

class Event
{
public:

	Event(string time, EventType type);

	void setIdSession(int idSession);

	virtual string toJson();

	virtual string toXML();

	virtual string toCSV();

protected:

	string timeStamp_;
	int idSession_;
	EventType type_;
	nlohmann::json j;
	tinyxml2::XMLDocument xml_;
	tinyxml2::XMLNode* eventRoot_;
};

