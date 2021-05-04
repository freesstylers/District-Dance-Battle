#include "JsonSerializer.h"

string JsonSerializer::serialize(Event* e)
{
	return e->toJson();
}
