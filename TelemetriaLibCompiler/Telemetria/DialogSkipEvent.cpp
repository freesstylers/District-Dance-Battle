#include "pch.h"
#include "DialogSkipEvent.h"

using namespace tinyxml2;

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

string DialogSkipEvent::toXML()
{
	Event::toXML();

	XMLElement* level = xml_.NewElement("level");
	level->SetText(level_);

	XMLElement* dialog_line = xml_.NewElement("dialog_line");
	dialog_line->SetText(dialog_line_);

	eventRoot_->InsertEndChild(level);
	eventRoot_->InsertEndChild(dialog_line);

	XMLPrinter printer_;

	xml_.Print(&printer_);
	return printer_.CStr();
}

string DialogSkipEvent::toCSV()
{
	string csv = Event::toCSV();
	csv += ", ";

	csv += std::to_string(level_);
	csv += ", ";

	csv += ", ";
	csv += ", ";
	csv += ", ";
	csv += ", ";
	csv += ", ";
	csv += ", ";
	csv += ", ";
	csv += ", ";
	csv += ", ";
	csv += std::to_string(dialog_line_);

	return csv;
}
