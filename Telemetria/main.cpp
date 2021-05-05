#include "Tracker.h"
#include "FilePersistence.h"
#include "JsonSerializer.h"

int main() {
	Tracker::GetInstance()->setIdSession(69);
	FilePersistence* f = new FilePersistence("../info.json");
	f->setSerializer(new JsonSerializer());
	Tracker::GetInstance()->setPersistenceObject(f);
	InputEvent inputE = Tracker::GetInstance()->createInputEvent(25.3f);
	Tracker::GetInstance()->getPersistenceObject()->Send(&inputE);
	return 0;
}