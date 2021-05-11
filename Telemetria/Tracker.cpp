#include "Tracker.h"

Tracker* Tracker::instance= nullptr;

Tracker::Tracker() {

}

void Tracker::setIdSession(int idSession) {
	idSession_ = idSession;
}

void Tracker::trackEvent(Event e) {
	eventCont_++;
	e.setIdSession(idSession_);
	eventQueue_.push(e);
}

void Tracker::setPersistenceObject(Persistence* persistence) {
	persistenceObject_ = persistence;
}

Persistence* Tracker::getPersistenceObject() {
	return persistenceObject_;
}


InputEvent Tracker::createInputEvent(float timeStamp) {
	InputEvent e = InputEvent(timeStamp);
	e.setIdSession(idSession_);
	return e;
}

LevelEvent Tracker::createLevelEvent(float timeStamp) {
	LevelEvent e = LevelEvent(timeStamp);
	e.setIdSession(idSession_);
	return e;
}

LogEvent Tracker::createLogEvent(float timeStamp) {
	LogEvent e = LogEvent(timeStamp);
	e.setIdSession(idSession_);
	return e;
}

void Tracker::sendEventsToPersistance() {
	for (int i = 0; i < eventCont_; i++) {
		Event e = eventQueue_.front();
		getPersistenceObject()->Send(&e);
		eventQueue_.pop();
	}
}