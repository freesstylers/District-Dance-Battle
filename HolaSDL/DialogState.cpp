#include "DialogState.h"
#include <fstream>
#include "Background.h"
#include "GameManager.h"
#include "Character.h"
#include "Squares.h"
#include "TextBox.h"
#include <iostream>
using namespace std;


DialogState::DialogState(GameManager* g, string txt, int numctrl):GameState(g)
{
	archivo = txt;
	controller = SDL_GameControllerOpen(numctrl);
	init();
}
//EL máximo de caracteres por cuadro es 46
void DialogState::init() 
{
	
	Dialog d;
	int aux;
	int sp;
	string textAux;
	
	ifstream file("resources/dialog/" + archivo + ".txt");
	if (file.is_open()) {
		file >> aux;
		for (int i = 0; i < aux; i++) {
			file >> sp;
			//sprites.push_back(new Background(manager, manager->getWindowWidth(), manager->getWindowHeight(), Vector2D(0, 0), sp));
			stage.push_back(new Background(manager, manager->getWindowWidth(), manager->getWindowHeight(), Vector2D(0, 0), sp));
		}
		file >> aux;
		//Sprites
		for (int i = 0; i < aux; i++) {
			file >> sp;
		//	sprites.push_back(new Character(manager,240 , 480, Vector2D(100 * (i*5), 100), sp));
			//stage.push_back(new Character(manager, 240, 480, Vector2D(100 * (i * 5), 100), sp));
		}
		file >> aux;
		for (int i = 0; i < aux; i++) {
			file >> sp;
			//Hay que crear una nueva clase que sea textBox
			file >> textAux;
			box.insert(pair<string, GameObject*>(textAux, new TextBox(manager, manager->getWindowWidth()-20, 65*5.5, Vector2D(10, 200),sp)));
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
			//file >> textAux;
		}
		file.close();
		actualBox = box[dialogo.front().box];

	}
		//dialogo.pop_front();
		stage.push_back(actualBox);
}
	
	
	


DialogState::~DialogState()
{
	delete actualBox;
}

void DialogState::render(Uint32 time, bool beatSync) {
	for (auto it : stage) {
		it->render(time, beatSync);
	}
	actualBox->render(time, beatSync);
	if (!dialogo.empty()) {
		if (dialogo.front().text.size() <= 29) {
			Texture msg0(manager->getRenderer(),
				dialogo.front().text,
				*(manager->getServiceLocator()->getFonts()->getFont(
					Resources::PIXEL30)), { COLOR(0xffffffff) });
			actualText = &msg0;
			actualText->render(manager->getRenderer(),
				manager->getWindowWidth() / 20 - 25, manager->getWindowHeight() / 1.31);
		}
		else {
			Texture msg0(manager->getRenderer(),
				dialogo.front().text,
				*(manager->getServiceLocator()->getFonts()->getFont(
					Resources::PIXEL20)), { COLOR(0xffffffff) });
			actualText = &msg0;
			actualText->render(manager->getRenderer(),
				manager->getWindowWidth() / 20 - 20, manager->getWindowHeight() / 1.40);
		}
	}
}

bool DialogState::handleEvent(Uint32 time, SDL_Event e) {
	if (e.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && keyup)
	{
		if (!dialogo.empty()) {
			actualBox = box[dialogo.front().box];
			dialogo.pop_front();
		
			keyup = false;
		}
		
	}
	else if (e.type == SDL_CONTROLLERBUTTONUP) keyup = true;
	return true;
}



