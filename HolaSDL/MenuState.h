#pragma once
#include "GameState.h"
#include "Button.h"
#include "EmptyObject.h"
#include "PanelMap.h"
#include <utility> 

using namespace std;

//struct Panel {
//	EmptyObject switches[3];
//	int height = 250;
//	int width = 100;
//	bool oneP_ = true;
//	bool facil_ = true;
//	int difficulty_;
//	string name_;
//	EmptyObject fondo_;
//	EmptyObject photo_;
//	Panel() : difficulty_(1), name_("") {
//		fondo_ = EmptyObject(nullptr, { 0,0 }, 0, 0, Resources::Point);
//		for (int i = 0; i < 3; i++) {
//			switches[i] = EmptyObject(nullptr, { 0,0 }, 0, 0, Resources::Point);
//		}
//		photo_ = EmptyObject(nullptr, { 0,0 }, 0, 0, Resources::Point);
//	}
//
//	Panel(GameManager* gm, Vector2D panelPos, int photo, string description, int difficulty, string name) : difficulty_(difficulty), name_(name) {
//		fondo_ = EmptyObject(gm, panelPos, width, height, Resources::Point);
//		for (int i = 0; i < 3; i++) {
//			switches[i] = EmptyObject(gm, Vector2D(((panelPos.getX() + width / 2) - width / 4), (panelPos.getY() + height / 2) + 2 * i*(height / 10)), width / 2, height / 10, Resources::Point);
//		}
//		photo_ = EmptyObject(gm, Vector2D(panelPos.getX() + width / 2, panelPos.getY() + height / 10), 2 * (width / 3), 7 * height / 10, photo);
//	}
//
//	void render(Uint32 time, bool beatHandler) {
//		fondo_.render(time, beatHandler);
//		for (int i = 0; i < 3; i++) {
//			switches[i].render(time, beatHandler);
//		}
//		photo_.render(time, beatHandler);
//	}
//};

//struct Par {
//	EmptyObject first;
//	PanelMap second;
//	
//};

class MenuState : public GameState //main class for menus
{
public:

	MenuState(GameManager* g);
	~MenuState();
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync);

private:
	

	pair <EmptyObject, PanelMap> buttons[5];

	int index = 0;
	int min = 0;
	int max = 4;

	static void play(GameManager* gameManager);
	static void load(GameManager* gameManager);
	static void exit(GameManager* gameManager);

	const Uint8 *keystates;
	SDL_GameController* controller = NULL;
	
	GameManager* gameManager;

	EmptyObject fondo__;

	void createMainButtons();
	void nextButton();
	void backButton();
	void reset();
	void deactivateAll();
	void activate(int first, int last);
	void buttonUse();

};