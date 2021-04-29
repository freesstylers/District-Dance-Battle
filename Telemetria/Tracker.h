#pragma once
#include "Event.h"
#include "LevelEvent.h"
#include "LogEvent.h"
#include "InputEvent.h"
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
 
	void trackEvent(Event e) {
		eventCont_++;
		e.setIdSession(idSession_);
		eventQueue_.push(e);
	}

	InputEvent createInputEvent(float timeStamp) {
		InputEvent e = InputEvent(timeStamp);
		return e;
	}

	LevelEvent createLevelEvent(float timeStamp) {
		LevelEvent e = LevelEvent(timeStamp);
		return e;
	}

	LogEvent createLogEvent(float timeStamp) {
		LogEvent e = LogEvent(timeStamp);
		return e;
	}


	// en clase Serializer ///////////////////////////////////
	void toJSON() {
		//Transformar los eventos de la queue
		for (Event e : eventQueue_) {
			string ev = serialize(e);
		}
		//Llamar a la clase de JSON
	}

	string serialize(Event e) {
		return "0";
	}
	/////////////////////////////////////////////////////

private:

	std::queue<Event> eventQueue_;

	static Tracker* instance;
	int idSession_;
	int eventCont_;

	Tracker() {

	}

};