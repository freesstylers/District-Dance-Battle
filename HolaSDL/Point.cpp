#include "Point.h"





Point::Point(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);

	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Point);
}

Point::~Point()
{
}
