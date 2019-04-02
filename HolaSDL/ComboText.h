#pragma once
#include "TextObject.h"
class ComboText :
	public TextObject
{
private:
	int screentime = 60;
	int lastUpdate = 0;
	double currentScale = 1;
	int alphaUpdate = -20;

public:
	ComboText(SDLGame* manager, Font* font, Vector2D pos);
	~ComboText();

	virtual void render(Uint32 time, bool beatSync = false);

	void updateCombo(int combo);
};

