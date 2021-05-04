#pragma once
#include "Serializer.h"

class JsonSerializer: public Serializer
{
public:

	JsonSerializer() {
	}
	virtual string serialize(Event* e);
};

