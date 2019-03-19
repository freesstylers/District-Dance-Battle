#include "DialogState.h"
#include <fstream>
#include "Background.h"
#include "GameManager.h"
#include "Character.h"
#include "Squares.h"
#include <iostream>
using namespace std;


DialogState::DialogState(GameManager* g, string txt):GameState(g)
{
	archivo = txt;
	init();
}

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
			sprites.push_back(new Background(manager, manager->getWindowWidth(), manager->getWindowHeight(), Vector2D(0, 0), sp));
		}
		file >> aux;
		for (int i = 0; i < aux; i++) {
			file >> sp;
			sprites.push_back(new Character(manager, manager->getWindowWidth(), manager->getWindowHeight(), Vector2D(100 * i, 100), sp));
		}
		file >> aux;
		for (int i = 0; i < aux; i++) {
			file >> sp;
			//Hay que crear una nueva clase que sea textBox
			file >> textAux;
			box.insert(pair<string, GameObject*>(textAux, new Character(manager, manager->getWindowWidth(), manager->getWindowHeight(), Vector2D(10, 400), sp)));
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

	}
	
	
}

DialogState::~DialogState()
{
}
