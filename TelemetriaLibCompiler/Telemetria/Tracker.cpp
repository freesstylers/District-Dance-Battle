#include "pch.h"

#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

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


InputEvent* Tracker::createInputEvent(string timeStamp) {
	InputEvent* e = new InputEvent(timeStamp);
	e->setIdSession(idSession_);
	return e;
}

LevelEvent* Tracker::createLevelEvent(string timeStamp) {
	LevelEvent* e = new LevelEvent(timeStamp);
	e->setIdSession(idSession_);
	return e;
}

LogEvent* Tracker::createLogEvent(string timeStamp) {
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

string Tracker::getTime() {

	time_t     now;
	struct tm* ts;
	char       buf[80];
	struct tm newtime;

	/* Obtener la hora actual */
	now = time(0);

	/* Formatear e imprimir el tiempo, "ddd yyyy-mm-dd hh:mm:ss zzz" */
	localtime_s(&newtime, &now);
	strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &newtime);

	return buf;
}