#include "EmptyObject.h"


EmptyObject::EmptyObject(SDLGame* game, Vector2D pos, int textura, int width, int height): GameObject(game)
{
	setPosition(pos);
	setTexture(game->getServiceLocator()->getTextures()->getTexture(textura));
	setWidth(width);
	setHeight(height);
}

EmptyObject::~EmptyObject()
{
}
