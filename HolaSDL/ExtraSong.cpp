#include "ExtraSong.h"
#include "GameManager.h"

ExtraSong::ExtraSong(GameManager* game_, Vector2D pos, int width, int height, int texture, string title_, string artist_, int lvl): EmptyObject(game_, pos, width, height, texture), level(lvl)
{
	title = new TextObject(game_, game_->getServiceLocator()->getFonts()->getFont(Resources::RETRO18), Vector2D(pos.getX() + 50, pos.getY() + 18));
	title->setText(title_ + " - " + artist_, SDL_Color{ (255), (255), (255), (255) });

	if (title->getWidth() > width * 0.7) {
		title->setText(title_ + " - ");
		float aux = title->getWidth() + 5;
		title->setText(title_ + " - " + artist_, SDL_Color{ (255), (255), (255), (255) }, aux);
	}

	diff = new TextObject(game_, game_->getServiceLocator()->getFonts()->getFont(Resources::RETRO20), Vector2D(pos.getX() + 50, pos.getY() + 60));
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

	string filename = "resources/data/" + to_string(level) + ".ddb";

	ifstream archivo(filename);

	//if the save file exists, then its data is loaded
	if (archivo.is_open()) {
		int mode;
		int scoreE = 0;

		archivo >> mode >> scoreE;
		maxScore = scoreE;
	}

	archivo.close();
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
