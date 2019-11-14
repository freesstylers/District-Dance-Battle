#include "DialogState.h"
#include <fstream>
#include "Background.h"
#include "GameManager.h"
#include "Character.h"
#include "Squares.h"
#include "TextBox.h"
#include <iostream>
using namespace std;


DialogState::DialogState(GameManager* g, int txt, int numctrl, bool oneP, bool hardMode, int prevMaxScoreE, int prevMaxScoreH): GameState(g), oneP_(oneP), hardMode_(hardMode), nlevel(txt)
{
	archivo = levels[txt];
	controller = SDL_GameControllerOpen(numctrl);
	prevMaxScoreE_ = prevMaxScoreE;
	prevMaxScoreH_ = prevMaxScoreH;
	init();
}


void DialogState::init()	//this method loads all the assets needed from the dialogue file
{

	Dialog d;
	int aux;
	int sp;
	string textAux;
	
	ifstream file("resources/dialog/" + archivo + ".txt");

	if (file.is_open()) {
		file >> aux;
		//Background
		for (int i = 0; i < aux; i++) {
			file >> sp;
			stage.push_back(new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), sp));
		}
		file >> aux;
		//Sprites
		for (int i = 0; i < aux; i++) {
			file >> sp;
			stage.push_back(new Character(manager, 240, 480, Vector2D(100 * (i * 3) + 600, 100), sp));
		}
		file >> aux;
		for (int i = 0; i < aux; i++) {
			file >> sp;
			//Dialogue
			file >> textAux;
			textBox = new TextBox(manager, manager->getDefaultWindowWidth() - 20, 400, Vector2D(10, manager->getDefaultWindowHeight() - 400), sp);
			box.insert(pair<string, GameObject*>(textAux, textBox));
		}

		file >> textAux;
		while (textAux != "0") {
			if (textAux == "-") {
				file >> d.box;
				file >> textAux;
				while (textAux != "-" && textAux != "0") {
					d.text = d.text + " " + textAux;
					file >> textAux;

				}
				dialogo.push_back(d);
				d.text = "";
			}

		}
		actualBox = box[dialogo.front().box];
		text = new TextObject(manager, manager->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(manager->getDefaultWindowWidth() / 22 + 10, manager->getDefaultWindowHeight() - 140));
		text->setText("AAA", { COLOR(0x00000000) }, textBox->getWidth() - 50);
		timer = new Timer();
		manager->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0, 1);
		manager->getServiceLocator()->getAudios()->setChannelVolume(10, 4);
		manager->getServiceLocator()->getAudios()->playChannel(Resources::Ambient, -1, 4);
		timer->Reset();
		updateText();
	}

	file.close();
}

//only used to update the timer
void DialogState::update(Uint32 time) 
{
	timer->Update();
	
	if (timer->DeltaTime() > .25)
	{
		beatSignal = true;
		timer->Reset();
	}
}

DialogState::~DialogState()
{
	bool check = false;
	delete timer;

	for (pair<string, GameObject*> i : box) {
		check = check || i.second == actualBox;
		delete i.second;
		i.second = nullptr;
	}

	box.clear();

	delete text;
	if(!check)
		delete actualBox;
}


void DialogState::render(Uint32 time, bool beatSync) {
	GameState::render(time, beatSignal);

 	actualBox->render(time, beatSync);
	text->render(time);
	beatSignal = false;
}

bool DialogState::handleEvent(Uint32 time, SDL_Event e) {

	GameState::handleEvent(time, e);
	
	//this handles how to advance the dialogue
	if ((e.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_SPACE || e.key.keysym.sym == SDLK_RETURN))) && keyup)
	{
		manager->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0, 1);
		if (!dialogo.empty()) {
			dialogo.pop_front();
			if (!dialogo.empty()) {
				actualBox = box[dialogo.front().box];
			}

			else if (archivo == "Corpselillo1" || archivo == "Onilecram1") { 
				actualBox = new TextBox(manager, manager->getDefaultWindowWidth() - 20, 400, Vector2D(10, manager->getDefaultWindowHeight() - 400), Resources::GreyDialog);
			}
			else 
 				actualBox = new TextBox(manager, manager->getDefaultWindowWidth() - 20, 400, Vector2D(10, manager->getDefaultWindowHeight() - 400), 131);

			updateText();

			keyup = false;
		}
		else if (end) {
			manager->getServiceLocator()->getAudios()->haltChannel(4);
			if (nlevel == 0)
				manager->getMachine()->changeState(new TutorialState(manager));
			else if(nlevel <= 5)
				manager->getMachine()->changeState(new PlayState(manager, nlevel, oneP_, hardMode_, prevMaxScoreE_, prevMaxScoreH_));
			else
				manager->getMachine()->changeState(new MapState(manager));
		}

	}
	else if (e.type == SDL_CONTROLLERBUTTONUP || e.type == SDL_KEYUP) keyup = true;

	else if (e.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) || (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_TAB || e.key.keysym.sym == SDLK_ESCAPE))) {

		manager->getServiceLocator()->getAudios()->haltChannel(4);
		if (nlevel == 0)
			manager->getMachine()->changeState(new TutorialState(manager));
		else if (nlevel <= 5)
			manager->getMachine()->changeState(new PlayState(manager, nlevel, oneP_, hardMode_, prevMaxScoreE_, prevMaxScoreH_));
		else
			manager->getMachine()->changeState(new MapState(manager));
	}

	return true;
}


void DialogState::updateText() {	//this method updates the text displayed on screen
	if (!dialogo.empty()) {

			text->setText(dialogo.front().text, { COLOR(0x00000000) }, manager->getDefaultWindowWidth() - 120);
	}
	else {
		if (archivo == "Intro2") {
			text->setText("COMIENZA TU AVENTURA", { COLOR(0x00000000) });
		}
		else if (nlevel <=5) {
			text->setText("COMIENZA LA BATALLA", { COLOR(0x00000000) });
		}
		else if(nlevel % 2 == 0){
			if (!hardMode_ && prevMaxScoreE_ < 600000) {
				text->setText("NIVEL COMPLETADO, HAS DESBLOQUEADO EL MODO DIFICIL", { COLOR(0x00000000) });
			}
			else {
				text->setText("HAS COMPLETADO EL NIVEL", { COLOR(0x00000000) });
			}
		}
		else {
			text->setText("NO HAS COMPLETADO EL NIVEL", { COLOR(0x00000000) });
		}

		end = true;
	}
}



