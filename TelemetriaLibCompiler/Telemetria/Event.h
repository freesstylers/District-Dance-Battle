#pragma once
#include <string>
#include "json.hpp"

using namespace std;

enum EventType {
	BASE_EVENT,
	LEVEL_EVENT,
	INPUT_EVENT,
	LOG_EVENT
};

static const char* enum_str[]{
	"BASE_EVENT",
	"LEVEL_EVENT",
	"INPUT_EVENT",
	"LOG_EVENT"
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

