#include "InputEvent.h"

InputEvent::InputEvent(float timeStamp) : Event(timeStamp, INPUT_EVENT) {
}

void InputEvent::setNLevel(int nLevel_) {
	nLevel = nLevel_;
}

void InputEvent::setPlayerButton(InputButton playerButton_) {
	playerButton = playerButton_;
}

void InputEvent::setLevelButton(InputButton levelButton_) {
	levelButton = levelButton_;
}

void InputEvent::setDistance(float distance_) {
	distance = distance_;
}

void InputEvent::setDistance(int numNote_) {
	numNote = numNote_;
}

string InputEvent::toJson()
{
	Event::toJson();
	j["nLevel"] = nLevel;
	j["playerButton"] = playerButton;
	j["levelButton"] = levelButton;
	j["distance"] = distance;
	j["numNote"] = numNote;
	return j.dump(4);
}
