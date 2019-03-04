#include "BarrasHUD.h"

BarrasHUD::BarrasHUD(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel,FondoBarra* fondo):
	GameObject(game), texture(texture)
{
	
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Nota);
	bar = fondo;

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
	if (position_.getX() < game_->getWindowWidth()-20-width_ ) { //en un 1 min 17 segundos recorre getWindowWidth()-20-width_ tenemos en cuenta que la cancion dura 2min  8 segundos
		position_.set(position_ + velocity_); 
	}
	if (bar->getPosition().getX() < game_->getWindowWidth() - 20- width_) {
		bar->setWidth(bar->getWidth() + velocity_.getX());
	}
	
}
