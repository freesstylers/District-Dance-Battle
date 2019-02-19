#include "Point.h"



Point::Point()
{
}

Point::Point(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Point);
	animation.firstFrameX = 0;
	animation.firstFrameY = 0;
	animation.nFramesX = 1;
	animation.nFramesY = 1;
	animation.totalFrames = 1;
	animation.currentFrame = 1;
	animation.spriteHeight = height;
	animation.spriteWidth = width;
}

/*void Point::render(Uint32 time)
{
	animation.texture_->render(getRect());
}*/
Point::~Point()
{
}
