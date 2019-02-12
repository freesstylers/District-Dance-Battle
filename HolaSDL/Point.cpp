#include "Point.h"



Point::Point()
{
}

Point::Point(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Point);
}

void Point::render(Uint32 time)
{
	texture->render(getRect());
}
Point::~Point()
{
}
