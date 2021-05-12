#include "pch.h"

#include <time.h>

Tracker* Tracker::instance= nullptr;

Tracker::Tracker() {
	idSession_ = -1;
	eventCont_ = 0;
	persistenceObject_ = nullptr;
	eventQueue_ = std::queue<Event*>();
}

void Tracker::setIdSession(int idSession) {
	idSession_ = idSession;
}

void Tracker::trackEvent(Event* e) {
	eventCont_++;
	e->setIdSession(idSession_);
	eventQueue_.push(e);
}

void Tracker::setPersistenceObject(Persistence* persistence) {
	persistenceObject_ = persistence;
}

Persistence* Tracker::getPersistenceObject() {
	return persistenceObject_;
}


InputEvent* Tracker::createInputEvent(float timeStamp) {
	InputEvent* e = new InputEvent(timeStamp);
	e->setIdSession(idSession_);
	return e;
}

LevelEvent* Tracker::createLevelEvent(float timeStamp) {
	LevelEvent* e = new LevelEvent(timeStamp);
	e->setIdSession(idSession_);
	return e;
}

LogEvent* Tracker::createLogEvent(float timeStamp) {
	LogEvent* e = new LogEvent(timeStamp);
	e->setIdSession(idSession_);
	return e;
}

void Tracker::sendEventsToPersistance() {
	for (int i = 0; i < eventCont_; i++) {
		Event* e = eventQueue_.front();
		getPersistenceObject()->Send(e);
		eventQueue_.pop();
		delete e;
	}
}

void Tracker::startTime() {
	start_ = 0;
}

double Tracker::getTime() {
	return difftime(time(0), start_);
}