#include "BarrasHUD.h"

BarrasHUD::BarrasHUD(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel):
	GameObject(game), texture(texture)
{
	
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Nota);
}
bool BarrasHUD::handleInput(Uint32 time, const SDL_Event& event) 
{
	return true;
}
BarrasHUD::~BarrasHUD()
{

}

void BarrasHUD::GetFrameBarra()
{

}

void BarrasHUD::update(Uint32 time)
{
	position_.set(position_ + velocity_);
}
