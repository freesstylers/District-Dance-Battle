#include "Perico.h"



Perico::Perico(SDLGame* game, double width, double height, Vector2D pos) :
	GameObject(game)
{
	setWidth(60*4);
	setHeight(120*4);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));


	animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::PericoIdle);

	animation.firstFrameX = 0;
	animation.firstFrameY = 0;
	animation.nFramesX = 3;
	animation.nFramesY = 1;
	animation.totalFrames = 4;
	animation.spriteWidth = 60;
	animation.spriteHeight = 120;

	framesPerSecond = 4;
}


Perico::~Perico()
{
}

bool Perico::handleInput(Uint32 time, const SDL_Event& event) {

	return false;
}

void Perico::update(Uint32 time) {


}

