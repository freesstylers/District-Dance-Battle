#include "pch.h"


Event::Event(float time, EventType type = BASE_EVENT) : timeStamp_(time), type_(type) {
}

void Event::setIdSession(int idSession) {
	idSession_ = idSession;
}

string Event::toJson()
{
	j["event_type"] = enum_str[type_];
	j["time_stamp"] = timeStamp_;
	j["id_session"] = idSession_;
	nlohmann::json aux = j;
	return aux.dump(4);
}
