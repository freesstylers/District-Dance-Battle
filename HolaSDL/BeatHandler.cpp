#include "BeatHandler.h"



BeatHandler::BeatHandler()
{
}


BeatHandler::~BeatHandler()
{
}
void BeatHandler::beatRateButton(int &currentBeats) {
	if (currentBeats >  0) {
		cout << currentBeats << " ";
		currentBeats = 0;
	}
	else


		currentBeats++;

}
