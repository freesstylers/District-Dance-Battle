#include "LogEvent.h"

LogEvent::LogEvent(float timeStamp) : Event(timeStamp, LOG_EVENT) {

}

string LogEvent::toJson()
{
	return j.dump(4);
}
