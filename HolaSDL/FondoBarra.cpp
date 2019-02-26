#include "FondoBarra.h"

FondoBarra::FondoBarra(SDLGame* game, double width, double height, Vector2D pos, double vel, int textura) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	vel_ = vel;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(textura);
}
bool FondoBarra::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}
void FondoBarra::update(Uint32 time)
{
	setWidth(width_+vel_);
	position_.set(position_);
}


FondoBarra::~FondoBarra()
{
}
