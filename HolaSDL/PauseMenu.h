#pragma once
#include "GameObject.h"
#include "EmptyObject.h"
#include "Button.h"
#include "Slider.h"

class PauseMenu :
	public GameObject
{
private:

	EmptyObject* bg;
	EmptyObject* options;
	EmptyObject* resume;
	EmptyObject* exit;

	EmptyObject* op_bg;
	EmptyObject* op_exit;
	Slider* music;
	Slider* sounds;
	EmptyObject* scale;

	list<GameObject*> menuButtons;
	list<GameObject*> optionsButtons;

	int selectedButton;

public:
	PauseMenu(SDLGame* game);
	~PauseMenu();
};