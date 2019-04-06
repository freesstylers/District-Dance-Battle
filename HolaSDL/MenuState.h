#pragma once
#include "GameState.h"
#include "Button.h"
#include "EmptyObject.h"
#include "PanelMap.h"
#include <utility> 

using namespace std;

class MenuState : public GameState //main class for menus
{
public:

	MenuState(GameManager* g);
	~MenuState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync);

private:
	
	struct Panel {
		EmptyObject switches[3];
		EmptyObject fondo_;
		EmptyObject photo_;
		int height = 300;
		int width = 200;
		int difficulty_;
		int index = 0;
		bool oneP_ = true;
		bool hardMode_ = false;
		bool difActive = false;
		string name_;
		string description_;
		Panel() : difficulty_(1), name_("") {
			fondo_ = EmptyObject();
			for (int i = 0; i < 3; i++) {
				switches[i] = EmptyObject();
			}
			photo_ = EmptyObject();
		}

		Panel(SDLGame* gm, Vector2D panelPos, int photo, string description, int difficulty, string name) : difficulty_(difficulty), name_(name) {
			fondo_ = EmptyObject(gm, panelPos, width, height, Resources::YellowBar);
			switches[0] = EmptyObject(gm, Vector2D(((panelPos.getX() + width / 2) - width / 6), (panelPos.getY() + height / 2) + (height / 24)), width / 3, height / 12, Resources::NumPlayersSwitch);
			switches[1] = EmptyObject(gm, Vector2D(((panelPos.getX() + width / 2) - width / 6), (panelPos.getY() + height / 2) + 5*(height / 24)), width / 3, height / 12, Resources::NumPlayersSwitch);
			switches[2] = EmptyObject(gm, Vector2D(((panelPos.getX() + width / 2) - width / 6), (panelPos.getY() + height / 2) + 9*(height / 24)), width / 3, height / 12, Resources::NumPlayersSwitch);
			photo_ = EmptyObject(gm, Vector2D(panelPos.getX() + width / 2, panelPos.getY() + height / 10), 2 * (width / 6), 3 * height / 10, photo);
			switches[index].scale(2);
		}

		void render(Uint32 time, bool beatHandler) {
			fondo_.render(time, beatHandler);
			for (int i = 0; i < 3; i++) {
				switches[i].render(time, beatHandler);
			}
			for (int i = 0; i < difficulty_; i++) {

			}
			photo_.render(time, beatHandler);
		}

		void reset() { 
			switches[index].scale(0.5);
			if (!oneP_) {
				oneP_ = true;
				switches[0].changeFrame();
			}
			if (hardMode_) {
				hardMode_ = false;
				switches[1].changeFrame();
			}
			index = 0; 
			switches[index].scale(2);
		}

		void prevSwitch() {
			switches[index].scale(0.5);
			if (index >= 2) { index = 0; }
			else { index++; }
			switches[index].scale(2);
		}

		void nextSwitch() {
			switches[index].scale(0.5);
			if (index <= 0) { index = 2; }
			else { index--; }
			switches[index].scale(2);
		}

		void selectButton() {
			switch (index)
			{
			case 0:
				oneP_ = !oneP_;
				switches[index].changeFrame();
				break;
			case 1:
				if(difActive) { 
					hardMode_ = !hardMode_; 
					switches[index].changeFrame();
				}
				break;
			case 2:
				//Cuando se pulsa va al play state con el nivel correspondiente
				break;
			}
		}
	};

	pair <EmptyObject, Panel> buttons[5];
	bool activeLevels[5];

	int index = 0;
	int min = 0;
	int max = 4;

	static void play(GameManager* gameManager);
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;
	
	GameManager * gameManager;

	EmptyObject fondo__;

	void createMainButtons();
	void nextButton();
	void backButton();

};