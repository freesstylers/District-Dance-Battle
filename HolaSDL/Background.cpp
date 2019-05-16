#include "Background.h"



Background::Background()
{
}

Background::Background(SDLGame* game, double width, double height, Vector2D pos, int texture) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(texture); 

	isAnimationSyncedToMusic = true;
	animation.currentFrame = 1;
}

Background::~Background()
{
}
