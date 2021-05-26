#include "pch.h"
#include "DialogSkipEvent.h"

DialogSkipEvent::DialogSkipEvent(string timeStamp): Event(timeStamp, DIALOG_SKIP_EVENT)
{
}

void DialogSkipEvent::setLevel(int level)
{
	level_ = level;
}

void DialogSkipEvent::setDialogLine(int dialog_line)
{
	dialog_line_ = dialog_line;
}

string DialogSkipEvent::toJson()
{
	Event::toJson();
	j["level"] = level_;
	j["dialog_line"] = dialog_line_;
	return j.dump(4);
}
