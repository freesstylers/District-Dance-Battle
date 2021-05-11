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

	Event(float time, EventType type);

	void setIdSession(int idSession);

	virtual string toJson();

protected:

	float timeStamp_;
	int idSession_;
	EventType type_;
	nlohmann::json j;
};

