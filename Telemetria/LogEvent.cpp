#include "LogEvent.h"

string LogEvent::toJson()
{
	return j.dump(4);
}
