#include "ComboText.h"



ComboText::ComboText(SDLGame* manager, Font* font, Vector2D pos) : TextObject(manager, font, pos)
{
	setActive(false);
	originalPos = pos;
	centeredPos = pos;
	particles = new ParticleEngine(60, pos, manager);
}


ComboText::~ComboText()
{
	delete particles;

	particles = nullptr;
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
		particles->render(time, false);
	}
	particles->update(time);
	
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
	game_->getServiceLocator()->getAudios()->playChannel(Resources::ComboSound, 0);
	switch (combo)
	{
	case 10:
		particles->generate(40);
		break;
	case 25:
		particles->generate(60);
		break;
	case 50:
		particles->generate(100);
		break;
	case 100:
		particles->generate(150);
		break;
	case 200:
		particles->generate(250);
		break;
	}
	setActive(true);
}
