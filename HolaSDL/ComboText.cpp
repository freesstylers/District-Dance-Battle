#include "ComboText.h"



ComboText::ComboText(SDLGame* manager, Font* font, Vector2D pos) : TextObject(manager, font, pos)
{
	setActive(false);
}


ComboText::~ComboText()
{
}

void ComboText::render(Uint32 time, bool beatSync)
{
	if (isActive()) {
		TextObject::render(time, beatSync);

		/*if (lastUpdate == 0)
			lastUpdate = time;

		if (currentScale != 1)
			currentScale -= (0.5 / (screentime / 3));

		if (time - lastUpdate >= screentime) {
			if (getAlpha() == 0)
				setActive(false);
			else
				changeAlpha(alphaUpdate);
		}*/
	}
}

void ComboText::updateCombo(int combo)
{
	setText(to_string(combo));

	currentScale = 1.5;
	scale(currentScale);
	setActive(true);
}
