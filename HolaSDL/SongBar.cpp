#include "SongBar.h"

SongBar::SongBar(SDLGame* game, double width, double height, Vector2D pos, int finalPos, BarBackground* backgroundBar, int songLength):
	GameObject(game), texture(texture), maxTSong(songLength), finalPos_(finalPos), bar(backgroundBar)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::NoteIcon);
}

bool SongBar::handleInput(Uint32 time, const SDL_Event& event) 
{
	return false;
}

SongBar::~SongBar()
{

}

//Updates the songbar and note position depending of the song time
void SongBar::update(Uint32 time)
{
	if (position_.getX() < game_->getDefaultWindowWidth()-82 ) {
		tSong += game_->deltaTime;
		double pos = (finalPos_ * tSong) / (maxTSong*1000);
		setPosition(Vector2D(pos + 41, getPosition().getY()));
		bar->setWidth(pos);
	}
}