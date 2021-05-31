#include "pch.h"
#include "XMLSerializer.h"

string XMLSerializer::serialize(Event* e)
{
	return e->toXML();
}

string XMLSerializer::openSerialization()
{
	return "<Root>\n";
}

string XMLSerializer::closeSerialization()
{
	return "</Root>\n";
}
