#include "pch.h"

string JsonSerializer::serialize(Event* e)
{
	return e->toJson();
}
