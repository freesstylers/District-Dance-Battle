#include "CreadorNiveles.h"
#include <Windows.h>
#include <mmsystem.h>
#include "GameManager.h"
//#include "PlayState.h"

CreadorNiveles::CreadorNiveles(GameManager* g) : GameState(g)
{
	controller = SDL_GameControllerOpen(0);
	string q[3] = { "Time (seconds): ", "BPM: ", "Song's Number (song's position): " };// , "Song's Name: "

	string a[3];
	for (int i = 0; i < 3; i++) {
		cout << q[i] << endl;
		cin >> a[i];
	}
	time = stoi(a[0]);
	bpm = stoi(a[1]);
	snumber = stoi(a[2]);
	beatsNumber = ((bpm / 60) * time) + 10; //10 beats for finish the song
	restBeats = beatsNumber;
	timer = new Timer();
	bh = new BeatHandler(bpm);
	medioBeat = (60.0 / bpm) / 2.0;
	Sleep(3000);
	
}

void CreadorNiveles::update(Uint32 time)
{
	GameState::update(time);
	if (start) {
		timer->Reset();
		manager->getServiceLocator()->getAudios()->playChannel(snumber, 0);
		start = false;
	}
	timer->Update();
	if (!aPressed && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
		SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))) {
		L = leftControl();
		aPressed = true;
	}
	else if (!(SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
		SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))) {
		aPressed = false;
	}
	if (!bPressed && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) ||
		SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))) {
		R = rightControl();
		bPressed = true;
	}
	else if (!(SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) ||
		SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))) {
		bPressed = false;
	}
	if (timer->DeltaTime() > (bh->getBeatTime() / 1000.0) - msDiff + medioBeat && restBeats > 0)
	{
		leftNotes.push_back(L);
		L = 0;
		rightNotes.push_back(R);
		R = 0;
		msDiff += timer->DeltaTime() - (bh->getBeatTime() / 1000.0);
		timer->Reset();
		restBeats--;
	}
	if (restBeats == 0) {
		finish();
	}
}

bool CreadorNiveles::handleEvent(Uint32 time, SDL_Event e)
{
	return false;
}

void CreadorNiveles::finish()
{
	ofstream myfile;// (".\resources\levels\"" + sname + ".txt");
	myfile.open("resources/levels/CL.txt");
	myfile << bpm << endl << time << endl << snumber << endl;
	for (int i = 0; i < beatsNumber; i++) {
		myfile << leftNotes[i] << " ";
		if (i % 50 == 0 && i != 0) {
			myfile << endl;
		}
	}
	myfile << endl << endl << -1 << endl << endl;
	for (int i = 0; i < beatsNumber; i++) {
		myfile << rightNotes[i] << " ";
		if (i % 50 == 0 && i != 0) {
			myfile << endl;
		}
	}
	myfile << endl << endl << -1;
	myfile.close();
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->changeState(new PlayState(manager, 100, true, false));
	//manager->exit_ = true;
}

int CreadorNiveles::leftControl()
{
	int number = 0;
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) { number = 1;	}
	else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) { number = 2; }
	else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP)) { number = 3; }
	else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN)) { number = 4; }
	return number;
}

int CreadorNiveles::rightControl()
{
	int number = 0;
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A)) { number = 1; }
	else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)) { number = 2; }
	else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X)) { number = 3; }
	else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y)) { number = 4; }
	return number;
}
