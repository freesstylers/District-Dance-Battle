#include "ExtraSong.h"
#include "GameManager.h"

ExtraSong::ExtraSong(GameManager* game_, Vector2D pos, int width, int height, int texture, string title_, string artist_, int lvl): EmptyObject(game_, pos, width, height, texture), level(lvl)
{
	title = new TextObject(game_, game_->getServiceLocator()->getFonts()->getFont(Resources::RETRO20), Vector2D(0, 0)); 
	title->setText(title_);

	artist = new TextObject(game_, game_->getServiceLocator()->getFonts()->getFont(Resources::RETRO20), Vector2D(0, 0));
	artist->setText(artist_);

	diff = new TextObject(game_, game_->getServiceLocator()->getFonts()->getFont(Resources::RETRO20), Vector2D(0, 0));
}

ExtraSong::~ExtraSong()
{
	delete artist;
	delete title;
	delete diff;
}

void ExtraSong::render(bool time)
{
	EmptyObject::render(time);

	artist->render(time);
	title->render(time);
	diff->render(time);
}
