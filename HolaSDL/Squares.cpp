#include "Squares.h"


Squares::Squares(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Square);

	isAnimationSyncedToMusic = true;
}


Squares::~Squares()
{
}
