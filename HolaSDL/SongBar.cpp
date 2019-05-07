#include "SongBar.h"

SongBar::SongBar(SDLGame* game, double width, double height, Vector2D pos, int finalPos, BarBackground* backgroundBar, int songLength):
	GameObject(game), texture(texture)
{
	maxTSong = songLength;
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	finalPos_ = finalPos;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::NoteIcon);
	bar = backgroundBar;
}
bool SongBar::handleInput(Uint32 time, const SDL_Event& event) 
{
	return false;
}
SongBar::~SongBar()
{

}

void SongBar::update(Uint32 time)
{
	if (position_.getX() < game_->getDefaultWindowWidth()-82 ) {
		tSong += game_->deltaTime;
		double pos = (finalPos_ * tSong) / (maxTSong*1000);
		setPosition(Vector2D(pos + 41, getPosition().getY()));
		bar->setWidth(pos);
	}
}