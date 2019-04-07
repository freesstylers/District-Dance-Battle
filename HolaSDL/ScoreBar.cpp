#include "ScoreBar.h"

ScoreBar::ScoreBar(SDLGame* game, double width, double height, Vector2D pos, double maxScore, double maxY) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	maxScore_ = maxScore;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::YellowBar);

	currentHeight = height;
	originalY_ = pos.getY();
	maxHeight_ = originalY_ - maxY;	//the maxY only represents the maximum y position, not the actual height (distance from the original y pos to the maximum y pos)
}

bool ScoreBar::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}

void ScoreBar::updateBar(double punt)
{
	double fraction = 0;

	fraction = (punt * maxHeight_) / maxScore_;

	currentHeight = fraction;

	setHeight(currentHeight);
	position_.setY(originalY_ - currentHeight); 
}


ScoreBar::~ScoreBar()
{
}

void ScoreBar::updateResolution(double wScale, double hScale)
{
	GameObject::updateResolution(wScale, hScale);

	maxHeight_ = maxHeight_ * hScale;
}
