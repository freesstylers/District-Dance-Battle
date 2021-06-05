#include "pch.h"

using namespace tinyxml2;

Event::Event(string time, EventType type = BASE_EVENT) : timeStamp_(time), type_(type) {
}

void Event::setIdSession(int idSession) {
	idSession_ = idSession;
}

string Event::toJson()
{
	j["event_type"] = event_enum_str[type_];
	j["time_stamp"] = timeStamp_;
	j["id_session"] = idSession_;
	nlohmann::json aux = j;
	return aux.dump(4);
}

string Event::toXML()
{
	eventRoot_ = xml_.NewElement(event_enum_str[type_]);

	xml_.InsertFirstChild(eventRoot_);

	XMLElement* timeStamp = xml_.NewElement("timeStamp");
	timeStamp->SetText(timeStamp_.c_str());
	XMLElement* idSession = xml_.NewElement("idSession");
	idSession->SetText(idSession_);

	eventRoot_->InsertEndChild(timeStamp);
	eventRoot_->InsertEndChild(idSession);

	XMLPrinter printer_;

	xml_.Print(&printer_);

	return printer_.CStr();
}

string Event::toCSV()
{
	string csv = "";

	csv += event_enum_str[type_];

	csv += ", ";

	csv += timeStamp_;

	csv += ", ";

	csv += std::to_string(idSession_);

	return csv;
}
