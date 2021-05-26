#include "pch.h"
#include "LostLevelEvent.h"

LostLevelEvent::LostLevelEvent(string timeStamp): LevelEvent(timeStamp, LOST_LEVEL_EVENT){
	last_note_ = -1;
}

void LostLevelEvent::setLastNote(int last_note)
{
	last_note_ = last_note;
}

string LostLevelEvent::toJson()
{
	LevelEvent::toJson();
	j["last_note"] = last_note_;
	return j.dump(4);
}
