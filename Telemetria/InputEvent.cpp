#include "InputEvent.h"

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
