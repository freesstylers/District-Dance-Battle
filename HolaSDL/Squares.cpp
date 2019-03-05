#include "Squares.h"



Squares::Squares()
{
}

Squares::Squares(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Square);
}


Squares::~Squares()
{
}
