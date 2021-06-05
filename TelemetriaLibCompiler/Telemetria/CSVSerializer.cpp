#include "pch.h"
#include "CSVSerializer.h"

string CSVSerializer::serialize(Event* e)
{
	return e->toCSV();
}

string CSVSerializer::openSerialization()
{
	string str = "event_type, timeStamp, idSession, level, playerButton, levelButton, distanceToNote, numNote, score, maxCombo, comboTime, input, lastNote, dialogLine";
	str += "\n";
	return str;
}
