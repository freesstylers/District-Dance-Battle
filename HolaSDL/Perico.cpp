#include "Perico.h"



Perico::Perico(SDLGame* game, double width, double height, Vector2D pos) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));


	animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::AnimTest);

	animation.firstFrameX = 0;
	animation.firstFrameY = 0;
	animation.nFramesX = 4;
	animation.nFramesY = 1;
	animation.totalFrames = 4;
	animation.currentFrame = 0;
	animation.spriteHeight = height;
	animation.spriteWidth = width;
}


Perico::~Perico()
{
}

bool Perico::handleInput(Uint32 time, const SDL_Event& event) {

	return false;
}

void Perico::update(Uint32 time) {


}

