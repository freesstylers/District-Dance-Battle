#pragma once
#include "TextObject.h"
class ComboText :
	public TextObject
{
private:
	int screentime = 500;
	int lastUpdate = 0;
	double currentScale;
	int alphaUpdate = -20;
	Vector2D originalPos;
	Vector2D centeredPos;
	double deltaScale = 0.1;

	bool hideAnimation = false;

public:
	ComboText(SDLGame* manager, Font* font, Vector2D pos);
	~ComboText();

	virtual void render(Uint32 time, bool beatSync = false);

	void updateCombo(int combo);

	void toggleHideAnimation() { hideAnimation = true; }
};

