#include "FondoBarra.h"

FondoBarra::FondoBarra(SDLGame* game, double width, double height, Vector2D pos, double vel) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	vel_ = vel;
	texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Bar);
}
void FondoBarra::handleInput(Uint32 time, const SDL_Event& event) {


}
void FondoBarra::update(Uint32 time)
{
	setWidth(width_+vel_);
	position_.set(position_);
}
void FondoBarra::render(Uint32 time)
{	
	texture->render(getRect());
}


FondoBarra::~FondoBarra()
{
}
