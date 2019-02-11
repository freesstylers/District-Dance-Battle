#include "BeatHandeler.h"



BeatHandeler::BeatHandeler()
{
}


BeatHandeler::~BeatHandeler()
{
}
void BeatHandeler::beatRateButton(int &currentBeats) {
	if (currentBeats > /*cola.beatsDeEspera*/ 0) {
		cout << currentBeats << " ";
		currentBeats = 0;
	}
	else


		currentBeats++;

}
double BeatHandeler::translateBmp() {
	beatTime = 60000 / bmp;
	return beatTime;
}