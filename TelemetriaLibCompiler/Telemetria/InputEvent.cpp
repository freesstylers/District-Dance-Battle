#include "pch.h"

using namespace tinyxml2;

InputEvent::InputEvent(string timeStamp) : Event(timeStamp, INPUT_EVENT) {
}

void InputEvent::setNLevel(int nLevel) {
	nLevel_ = nLevel;
}

void InputEvent::setPlayerButton(InputButton playerButton) {
	playerButton_ = playerButton;
}

void InputEvent::setLevelButton(InputButton levelButton) {
	levelButton_ = levelButton;
}

void InputEvent::setDistance(float distance) {
	distance_ = distance;
}

void InputEvent::setNumNote(int numNote) {
	numNote_ = numNote;
}

string InputEvent::toJson()
{
	Event::toJson();
	j["nLevel"] = nLevel_;
	j["playerButton"] = playerButton_;
	j["levelButton"] = levelButton_;
	j["distance"] = distance_;
	j["numNote"] = numNote_;
	return j.dump(4);
}

string InputEvent::toXML()
{
	Event::toXML();

	XMLElement* nLevel = xml_.NewElement("nLevel");
	nLevel->SetText(nLevel_);

	XMLElement* playerButton = xml_.NewElement("playerButton");
	playerButton->SetText(playerButton_);

	XMLElement* levelButton = xml_.NewElement("levelButton");
	levelButton->SetText(levelButton_);

	XMLElement* distance = xml_.NewElement("distance");
	distance->SetText(distance_);

	XMLElement* numNote = xml_.NewElement("numNote");
	numNote->SetText(numNote_);

	eventRoot_->InsertEndChild(nLevel);
	eventRoot_->InsertEndChild(playerButton);
	eventRoot_->InsertEndChild(levelButton);
	eventRoot_->InsertEndChild(distance);
	eventRoot_->InsertEndChild(numNote);

	XMLPrinter printer_;

	xml_.Print(&printer_);
	return printer_.CStr();
}
