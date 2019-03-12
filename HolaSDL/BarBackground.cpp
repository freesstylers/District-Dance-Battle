#include "BarBackground.h"

BarBackground::BarBackground(SDLGame* game, double width, double height, Vector2D pos, double vel, int texture) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	vel_ = vel;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(texture);
}
bool BarBackground::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}

BarBackground::~BarBackground()
{
}
