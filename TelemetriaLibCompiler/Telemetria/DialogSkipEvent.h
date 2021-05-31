#pragma once
#include "Event.h"

class DialogSkipEvent: public Event
{
public:
	DialogSkipEvent(string timeStamp);
	void setLevel(int level);
	void setDialogLine(int dialog_line);
	string toJson();
	string toXML();

private:
	int level_;
	int dialog_line_;
};

