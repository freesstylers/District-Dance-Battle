#include "Flechas.h"


Flechas::Flechas()
{

}
Flechas::Flechas(SDL_GameControllerButton key, SDLGame* game, double width, double height, Vector2D pos, Vector2D vel) :
	GameObject(game), key(key)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	switch (key) {
	case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaLeft);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaRight);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_UP:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaUp);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaDown);
		break;
	case SDL_CONTROLLER_BUTTON_A:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BotonA);
		break;
	case SDL_CONTROLLER_BUTTON_B:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BotonB);
		break;
	case SDL_CONTROLLER_BUTTON_X:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BotonX);
		break;
	case SDL_CONTROLLER_BUTTON_Y:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BotonY);
		break;
	}

	animation.firstFrameX = 0;
	animation.firstFrameY = 0;
	animation.nFramesX = 1;
	animation.nFramesY = 1;
	animation.totalFrames = 1;
	animation.currentFrame = 1;
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

