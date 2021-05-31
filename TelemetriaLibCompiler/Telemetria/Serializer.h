#pragma once
#include "Event.h"
#include <string>
using namespace std;

class Serializer
{
public:
    Serializer() {}
    virtual string serialize(Event* e)=0;
    virtual string openSerialization() { return ""; };
    virtual string closeSerialization() { return ""; };
};

