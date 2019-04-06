#include "ScoreBar.h"

ScoreBar::ScoreBar(SDLGame* game, double width, double height, Vector2D pos, int maxScore, int maxHeight) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	maxScore_ = maxScore;
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

	fraction = (punt * maxHeight_) / (double)maxScore_;

	currentHeight = fraction;

	setHeight(currentHeight);
	position_.setY(originalHeight - currentHeight); 
}


ScoreBar::~ScoreBar()
{
}

void ScoreBar::updateResolution(double wScale, double hScale)
{
	GameObject::updateResolution(wScale, hScale);

	maxHeight_ = maxHeight_ * hScale;
}
