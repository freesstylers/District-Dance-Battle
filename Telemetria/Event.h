#pragma once

class Event
{
public:

	Event(float time): timeStamp_(time) {

	}

	void setIdSession(int idSession) {
		idSession_ = idSession;
	}

protected:

	float timeStamp_;
	int idSession_;

};

