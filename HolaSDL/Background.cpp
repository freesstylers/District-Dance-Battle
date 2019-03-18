#include "Background.h"



Background::Background()
{
}

Background::Background(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::testBG); //el fondo es un objeto vacio, solo tiene un sprite, deberiamos cambiar la llamada de la textura(?)
																								 //hacer la llamada de textura en el PlayState como hace BarBackground
}

Background::~Background()
{
}
