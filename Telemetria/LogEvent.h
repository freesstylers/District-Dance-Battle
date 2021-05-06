#pragma once
#include "Event.h"
class LogEvent :
    public Event
{
public:
    LogEvent(float timeStamp);

    virtual string toJson();
};

