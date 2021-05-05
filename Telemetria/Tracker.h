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

	void setIdSession(int idSession) {
		idSession_ = idSession;
	}
 
	void trackEvent(Event* e) {
		eventCont_++;
		e->setIdSession(idSession_);
		eventQueue_.push(e);
	}

	void setPersistenceObject(Persistence* persistence) {
		persistenceObject_ = persistence;
	}

	Persistence* getPersistenceObject() {
		return persistenceObject_;
	}


	InputEvent createInputEvent(float timeStamp) {
		InputEvent e = InputEvent(timeStamp);
		e.setIdSession(idSession_);
		return e;
	}

	LevelEvent createLevelEvent(float timeStamp) {
		LevelEvent e = LevelEvent(timeStamp);
		e.setIdSession(idSession_);
		return e;
	}

	LogEvent createLogEvent(float timeStamp) {
		LogEvent e = LogEvent(timeStamp);
		e.setIdSession(idSession_);
		return e;
	}

private:

	std::queue<Event*> eventQueue_;

	static Tracker* instance;
	int idSession_;
	int eventCont_;

	Persistence* persistenceObject_;

	Tracker() {

	}

};