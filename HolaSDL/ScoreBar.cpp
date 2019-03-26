#include "ScoreBar.h"

ScoreBar::ScoreBar(SDLGame* game, double width, double height, Vector2D pos, int noteAmount, int maxHeight, int texture) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	noteAmount_ = noteAmount;
	maxHeight_ = maxHeight;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(texture);

	currentHeight = height;
	originalHeight = pos.getY();
}

bool ScoreBar::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}

void ScoreBar::updateBar(int punt)
{
	double fraction = 0;

	fraction = ((double)maxHeight_ / (double)noteAmount_) * (1.0 / punt); //obtencion de crecimiento de puntuacion, se realiza un cociente para casos en los que la puntuacion no sea la maxima (>perfecto)

	currentHeight = currentHeight + fraction;

	setHeight(currentHeight);
	position_.setY(originalHeight - currentHeight); //restamos altura para que crezca en la direccion deseada, en este caso hacia arriba
}


ScoreBar::~ScoreBar()
{
}