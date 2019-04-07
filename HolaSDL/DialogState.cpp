#include "DialogState.h"
#include <fstream>
#include "Background.h"
#include "GameManager.h"
#include "Character.h"
#include "Squares.h"
#include "TextBox.h"
#include <iostream>
using namespace std;


DialogState::DialogState(GameManager* g, int txt, int numctrl):GameState(g)
{
	archivo = levels[txt];
	controller = SDL_GameControllerOpen(numctrl);
	init();
}
//EL máximo de caracteres por cuadro es 35*2 = 70, contando espacios y el primer espacio
void DialogState::init() 
{
	
	Dialog d;
	int aux;
	int sp;
	string textAux;
	
	ifstream file("resources/dialog/" + archivo + ".txt");
	
	if (file.is_open()) {
		file >> nlevel;
		file >> twoPlayers;
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
			box.insert(pair<string, GameObject*>(textAux, new TextBox(manager, manager->getWindowWidth()-20, 65*5.5, Vector2D(10, manager->getWindowHeight()-65*5.5),sp)));
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
		//stage.push_back(actualBox);
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
		if (dialogo.front().text.size() <= 35) {
		
			Texture msg0(manager->getRenderer(),
				dialogo.front().text,
				*(manager->getServiceLocator()->getFonts()->getFont(
					Resources::PIXEL20)), { COLOR(0xffffffff) });
			actualText = &msg0;
			actualText->render(manager->getRenderer(),
				manager->getWindowWidth() / 39, manager->getWindowHeight() - 65 * 1.9);
		}
		else {
			string aux1="";
			string aux2="";
			int intaux;
			for (int i = 0; i < 35; i++) {
				aux1 += dialogo.front().text[i];
				intaux = i;
			}
			intaux++;
			while (intaux < dialogo.front().text.size()) {
				aux2 += dialogo.front().text[intaux];
				intaux++;
			}
			Texture msg0(manager->getRenderer(),
				aux1,
				*(manager->getServiceLocator()->getFonts()->getFont(
					Resources::PIXEL20)), { COLOR(0xffffffff) });
			actualText = &msg0;
			actualText->render(manager->getRenderer(),
				manager->getWindowWidth() / 39, manager->getWindowHeight() - 65 * 1.9);
			if (aux2 != "") {
				Texture msg1(manager->getRenderer(),
					aux2,
					*(manager->getServiceLocator()->getFonts()->getFont(
						Resources::PIXEL20)), { COLOR(0xffffffff) });
				actualText = &msg1;
				actualText->render(manager->getRenderer(),
					manager->getWindowWidth() / 19, (manager->getWindowHeight() - 65 * 1.9) + 40);
				
			}
			
		}
	}
	else {
		Texture msg0(manager->getRenderer(),
			" COMIENZA LA BATALLA",
			*(manager->getServiceLocator()->getFonts()->getFont(
				Resources::PIXEL20)), { COLOR(0xffffffff) });
		actualText = &msg0;
		actualText->render(manager->getRenderer(),
			manager->getWindowWidth() / 39, manager->getWindowHeight() - 65 * 1.9);
		end = true;
	}
}

bool DialogState::handleEvent(Uint32 time, SDL_Event e) {
	if ((e.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && keyup) || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE))
	{
		if (!dialogo.empty()) {
			dialogo.pop_front();
			if (!dialogo.empty()) {
				actualBox = box[dialogo.front().box];
			}
			else actualBox = new TextBox(manager, manager->getWindowWidth() - 20, 65 * 5.5, Vector2D(10, manager->getWindowHeight() - 65 * 5.5),30);

		
			keyup = false;
		}
		if (end) {
			manager->getMachine()->changeState(new PlayState(manager, nlevel,twoPlayers));
		}
		
	}
	else if (e.type == SDL_CONTROLLERBUTTONUP) keyup = true;

	else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_TAB)
		manager->getMachine()->changeState(new PlayState(manager, nlevel, twoPlayers));
	return true;
}



