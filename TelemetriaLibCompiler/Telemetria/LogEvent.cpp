#include "pch.h"


LogEvent::LogEvent(float timeStamp) : Event(timeStamp, LOG_EVENT) {

}

string LogEvent::toJson()
{
	Event::toJson();
	return j.dump(4);
}
