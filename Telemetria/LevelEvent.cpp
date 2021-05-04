#include "LevelEvent.h"

string LevelEvent::toJson()
{
	j["level"] = level_;
	j["score"] = score_;
	
	return j.dump(4);
}
