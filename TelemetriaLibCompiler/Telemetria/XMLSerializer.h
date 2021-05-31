#include "Serializer.h"

class XMLSerializer :public Serializer
{
public:
	XMLSerializer() {
	}
	virtual string serialize(Event* e);
	virtual string openSerialization();
	virtual string closeSerialization();
};

