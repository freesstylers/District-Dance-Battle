#pragma once
#include "Event.h"
#include "LevelEvent.h"
#include "LogEvent.h"
#include "InputEvent.h"
#include "Persistence.h"
#include <queue>

class Tracker {

public:

	static Tracker* GetInstance() {
		if (instance == nullptr) {
			instance = new Tracker();
		}
		return instance;
	}

	void setIdSession(int idSession);
 
	void trackEvent(Event* e);

	void setPersistenceObject(Persistence* persistence);

	Persistence* getPersistenceObject();


	InputEvent* createInputEvent(string timeStamp);

	LevelEvent* createLevelEvent(string timeStamp);

	LogEvent* createLogEvent(string timeStamp);

	void sendEventsToPersistance();


	void startTime();

	string getTime();

private:

	std::queue<Event*> eventQueue_;

	static Tracker* instance;
	int idSession_;
	int eventCont_;

	Persistence* persistenceObject_;

	Tracker();

	time_t start_;

};