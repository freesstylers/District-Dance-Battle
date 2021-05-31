#pragma once
#include "Event.h"
class LogEvent :
    public Event
{
public:
    LogEvent(string timeStamp);

    virtual string toJson();
    virtual string toXML();
};

