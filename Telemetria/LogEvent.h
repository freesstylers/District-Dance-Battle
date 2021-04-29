#pragma once
#include "Event.h"
class LogEvent :
    public Event
{
public:
    LogEvent(float timeStamp): Event(timeStamp) {

    }
};

