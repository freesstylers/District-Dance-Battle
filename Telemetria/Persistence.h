#pragma once
#include "Event.h"
#include "Serializer.h"

class Persistence
{
protected:
	Serializer* serializerObject=nullptr;
public:
	Persistence() {
	}
	virtual void Send(Event* e)=0;
	virtual void Flush()=0;
	void setSerializer(Serializer* s) {
		serializerObject = s;
	}
};

