#include "Event.h"

string Event::toJson()
{
	j["event_type"] = enum_str[type_];
	j["time_stamp"] = timeStamp_;
	j["id_session"] = idSession_;
	nlohmann::json aux = j;
	return aux.dump(4);
}
