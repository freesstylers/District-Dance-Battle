#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class BeatHandeler
{
protected:
	//int currentBeats ;
	int bmp;
	double beatTime;
public:
	BeatHandeler();
	BeatHandeler(int bmp) :bmp(bmp) {};
	~BeatHandeler();
	//Este es el m�todo que controla cuando y a que velocidad se va a lanzar cada bot�n
	void beatRateButton(int &currentBeats/*aqui deber�a de entrar la cola con los botones y los tiempos*/);
	//Metodo que combierte los bpm a el tiempo transcurrido entre beat y beat
	double translateBmp();
	//Devuelve el beattime
	double getBeatTime() { return beatTime; };

};
//CODIGO PARA PONER EN EL DEMO GAME O EN EL MUSIC TIMER
/*exit_ = false;
	int nbeats =0;
	//getServiceLocator()->getAudios()->playMusic (Resources::Explosion, -1);
	getServiceLocator()->getAudios()->playChannel(Resources::MainSong, -1);
	getServiceLocator()->getAudios()->setChannelVolume(10);
	Uint32 lastIterationTime = SDL_GetTicks();
	while (!exit_) {
		//// PARTE IMPORTANTE PARA EL SONIDO/////////////////////
		Uint32 startTime = SDL_GetTicks();
		BeatHandeler* b = new BeatHandeler(112);
		b->translateBmp();
		if (SDL_GetTicks() > lastIterationTime + b->getBeatTime()-5 && SDL_GetTicks() < lastIterationTime + b->getBeatTime() + 5) {
			b->beatRateButton(nbeats);
			lastIterationTime = SDL_GetTicks();
		}
		/////////////////////////////////// */
