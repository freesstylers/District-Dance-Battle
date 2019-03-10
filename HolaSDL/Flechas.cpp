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
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::FlechaLeft);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::FlechaRight);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_UP:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::FlechaUp);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::FlechaDown);
		break;
	case SDL_CONTROLLER_BUTTON_A:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::BotonA);
		break;
	case SDL_CONTROLLER_BUTTON_B:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::BotonB);
		break;
	case SDL_CONTROLLER_BUTTON_X:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::BotonX);
		break;
	case SDL_CONTROLLER_BUTTON_Y:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::BotonY);
		break;
	}


}

Flechas::~Flechas()
{

}

bool Flechas::handleInput(Uint32 time, const SDL_Event& event) {

	return false;
}

void Flechas::update(Uint32 time) {
	double deltaTime = getGame()->deltaTime;
	position_.set(position_ + velocity_ * deltaTime);
}

