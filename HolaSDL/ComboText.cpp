#include "ComboText.h"



ComboText::ComboText(SDLGame* manager, Font* font, Vector2D pos) : TextObject(manager, font, pos)
{
	setActive(false);
	originalPos = pos;
	centeredPos = pos;
}


ComboText::~ComboText()
{
}

void ComboText::render(Uint32 time, bool beatSync)
{
	if (isActive()) {
		TextObject::render(time, beatSync);

		if (lastUpdate == 0)
			lastUpdate = time;

		if (currentScale >= 1.53) {
			deltaScale = -deltaScale;
		}

		if (currentScale > 0.9) {
			currentScale += (deltaScale / (screentime / 40));
			setHeight(text->getHeight());
			setWidth(text->getWidth());
			setPosition(centeredPos);
			scale(currentScale);
		}

		if (hideAnimation && time - lastUpdate >= screentime) {
			if (getAlpha() == 0)
				setActive(false);
			else
				changeAlpha(alphaUpdate);
		}
	}
}

void ComboText::updateCombo(int combo)
{
	setText("x" + to_string(combo));
	lastUpdate = 0;
	setAlpha(255);
	deltaScale = abs(deltaScale);

	currentScale = 1.5;
	setHeight(text->getHeight());
	setWidth(text->getWidth());
	centeredPos = originalPos - Vector2D(text->getWidth() / 2, 0);
	setPosition(centeredPos);

	scale(currentScale);

	setActive(true);
}
