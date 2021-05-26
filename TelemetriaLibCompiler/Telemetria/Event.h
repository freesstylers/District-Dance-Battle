#pragma once
#include <string>
#include "json.hpp"

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

enum InputType {
	PS4_INPUT,
	XBOX_INPUT,
	KEYBOARD_INPUT
};

static const char* input_enum_str[]{
	"PS4_INPUT",
	"XBOX_INPUT",
	"KEYBOARD_INPUT"
};

class Event
{
public:

	Event(string time, EventType type);

	void setIdSession(int idSession);

	virtual string toJson();

protected:

	string timeStamp_;
	int idSession_;
	EventType type_;
	nlohmann::json j;
};

