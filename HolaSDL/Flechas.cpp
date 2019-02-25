#include "Flechas.h"


Flechas::Flechas()
{

}
Flechas::Flechas(SDL_Keycode key, SDLGame* game, double width, double height, Vector2D pos, Vector2D vel) :
	GameObject(game), key(key)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	switch (key) {
	case SDLK_LEFT:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaLeft);
		break;
	case SDLK_RIGHT:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaRight);
		break;
	case SDLK_UP:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaUp);
		break;
	case SDLK_DOWN:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaDown);
		break;
	}

	animation.firstFrameX = 0;
	animation.firstFrameY = 0;
	animation.nFramesX = 1;
	animation.nFramesY = 1;
	animation.totalFrames = 1;
	animation.spriteHeight = height;
	animation.spriteWidth = width;
}

Flechas::~Flechas()
{

}

bool Flechas::handleInput(Uint32 time, const SDL_Event& event) {

	return false;
}

void Flechas::update(Uint32 time) {
	position_.set(position_ + velocity_);
}

