#include "Flechas.h"

#include "GameManager.h"

Flechas::Flechas()
{

}
Flechas::Flechas(SDL_Scancode key, GameManager* game, double width, double height, Vector2D pos, Vector2D vel) :
	GameObject(game), key(key)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	switch (key) {
	case SDL_SCANCODE_LEFT:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaLeft);
		break;
	case SDL_SCANCODE_RIGHT:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaRight);
		break;
	case SDL_SCANCODE_UP:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaUp);
		break;
	case SDL_SCANCODE_DOWN:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaDown);
		break;
	case SDL_SCANCODE_A:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BotonA);
		break;
	case SDL_SCANCODE_B:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BotonB);
		break;
	case SDL_SCANCODE_X:
		animation.texture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BotonX);
		break;
	case SDL_SCANCODE_Y:
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

