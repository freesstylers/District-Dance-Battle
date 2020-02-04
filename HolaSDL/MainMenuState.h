#pragma once
#include "GameState.h"
#include "EmptyObject.h"
#include "GameManager.h"
#include "checkML.h"

//The main menu's state

using namespace std;
class MainMenuState :
	public GameState
{
public:
	MainMenuState(GameManager* g);
	~MainMenuState();
	static void newGame(GameManager*gameManager);
	
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatHandler);

	vector<EmptyObject*> buttons;
	vector<bool> selectButton;

private:
	GameManager* gameManager;
	void nextButton();
	void backButton();
	int index = 0;
	int max=4;
	int min = 0;

	bool confirmationActive = false;
	bool keyup = true;

	void exit(GameManager* gameManager);


	SDL_GameController* controller = NULL;

	EmptyObject* op_bg;
	EmptyObject* music;
	EmptyObject* musicSelect;
	EmptyObject* sounds;
	EmptyObject* soundsSelect;
	EmptyObject* controls;
	EmptyObject* controlsSelect;
	EmptyObject* controls2;
	EmptyObject* controlsSelect2;
	EmptyObject* op_exit;

	EmptyObject* confirmation;
	EmptyObject* selection;

	TextObject* musicTxt;
	TextObject* soundTxt;
	TextObject* controlTxt;
	TextObject* control2Txt;

	vector<EmptyObject*> optionsButtons;

	int selectedButton = 0;
	bool optionsOpen = false;
	
	int P1Controller;
	int P2Controller;
	
	SDL_Haptic* haptics;
	int aux = 0;

	void options();
	void updateMusic(bool raise);
	void updateSound(bool raise);
	void updateControlsP1(bool raise);
	void updateControlsP2(bool raise);
	void updateTxt();
};

