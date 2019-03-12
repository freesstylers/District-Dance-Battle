#include "SongBar.h"

SongBar::SongBar(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel, BarBackground* backgroundBar):
	GameObject(game), texture(texture)
{
	
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::NoteIcon);
	bar = backgroundBar;

}
bool SongBar::handleInput(Uint32 time, const SDL_Event& event) 
{
	return true;
}
SongBar::~SongBar()
{

}

void SongBar::update(Uint32 time)
{
	if (position_.getX() < game_->getWindowWidth()-20-width_ ) {
		position_.set(position_ + velocity_); 
		bar->setWidth(bar->getWidth() + velocity_.getX());
	} 
}
