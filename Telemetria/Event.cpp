#include "Event.h"

string Event::toJson()
{
	j["event_type"] = type_;
	j["time_stamp"] = timeStamp_;
	j["id_session"] = idSession_;
	return j.dump(4);
}
