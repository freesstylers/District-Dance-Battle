#include "ExtraSong.h"
#include "GameManager.h"

ExtraSong::ExtraSong(GameManager* game_, Vector2D pos, int width, int height, int texture, string title_, string artist_, int lvl): EmptyObject(game_, pos, width, height, texture), level(lvl)
{
	title = new TextObject(game_, game_->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(pos.getX() + 50, pos.getY() + 15)); 
	title->setText(title_ + " - " + artist_);

	diff = new TextObject(game_, game_->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(pos.getX() + 50, pos.getY() + 50));
	switch (texture) {
	case Resources::CancionExtraFacil:
		diff->setText("EASY");
		break;
	case Resources::CancionExtraNormal:
		diff->setText("NORMAL");

		break;
	case Resources::CancionExtraDificil:
		diff->setText("HARD");

		break;
	}
}

ExtraSong::~ExtraSong()
{
	delete title;
	delete diff;
}

void ExtraSong::render(bool time)
{
	EmptyObject::render(time);

	title->render(time);
	diff->render(time);
}
