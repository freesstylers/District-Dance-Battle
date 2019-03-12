#include "ScoreBar.h"

ScoreBar::ScoreBar(SDLGame* game, double width, double height, Vector2D pos, int noteAmount, int maxHeight) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	noteAmount_ = noteAmount;
	maxHeight_ = maxHeight;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::YellowBar);

	currentHeight = height;
	originalHeight = pos.getY();
}

bool ScoreBar::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}

void ScoreBar::updateBar(int punt)
{
	double fraction = 0;

	fraction = ((double)maxHeight_ / (double)noteAmount_) * (1.0 / punt);

	currentHeight = currentHeight + fraction;

	setHeight(currentHeight);
	position_.setY(originalHeight - currentHeight);
}

void ScoreBar::update(Uint32 time)
{
	//position_.set(position_);
}


ScoreBar::~ScoreBar()
{
}