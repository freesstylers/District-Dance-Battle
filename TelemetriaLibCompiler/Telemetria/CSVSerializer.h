#pragma once
#include "Serializer.h"
class CSVSerializer : public Serializer
{
public:
	CSVSerializer() {};
	virtual string serialize(Event* e);
	virtual string openSerialization();
};

