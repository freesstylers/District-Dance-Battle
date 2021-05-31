#include "pch.h"
#include "LostLevelEvent.h"

using namespace tinyxml2;

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

string LostLevelEvent::toXML()
{
	LevelEvent::toXML();

	XMLElement* last_note = xml_.NewElement("last_note");
	last_note->SetText(last_note_);

	eventRoot_->InsertEndChild(last_note);

	XMLPrinter printer_;

	xml_.Print(&printer_);
	return printer_.CStr();
}
