#include "Background.h"



Background::Background()
{
}

Background::Background(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::FondoPrueba);
}

Background::~Background()
{
}
