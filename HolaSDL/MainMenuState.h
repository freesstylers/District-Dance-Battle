#pragma once
#include "GameState.h"
#include "EmptyObject.h"
#include "GameManager.h"
#include "checkML.h"

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

	pair<EmptyObject*, bool> buttons[4];

private:
	GameManager* gameManager;
	void nextButton();
	void backButton();
	int index = 0;
	int max=3;
	int min = 0;

	void exit(GameManager* gameManager);

	
	SDL_GameController* controller = NULL;

	EmptyObject* op_bg;
	EmptyObject* music;
	EmptyObject* musicSelect;
	EmptyObject* sounds;
	EmptyObject* soundsSelect;
	EmptyObject* controls;
	EmptyObject* controlsSelect;
	EmptyObject* op_exit;

	EmptyObject* selection;

	TextObject* musicTxt;
	TextObject* soundTxt;
	TextObject* controlTxt;

	vector<EmptyObject*> optionsButtons;

	int selectedButton = 0;
	bool optionsOpen = false;
	bool isXbox;

	void options();
	void updateMusic(bool raise);
	void updateSound(bool raise);
	void updateControls();
	void updateTxt();
};

