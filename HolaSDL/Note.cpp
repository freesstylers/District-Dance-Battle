#include "Note.h"


Note::Note()
{

}
Note::Note(SDL_GameControllerButton key, SDLGame* game, double width, double height, Vector2D pos, Vector2D vel) :
	GameObject(game), key(key)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);

	switch (key) {
	case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::LeftArrow);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::RightArrow);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_UP:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::UpArrow);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::DownArrow);
		break;
	case SDL_CONTROLLER_BUTTON_A:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::AButton);
		break;
	case SDL_CONTROLLER_BUTTON_B:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::BButton);
		break;
	case SDL_CONTROLLER_BUTTON_X:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::XButton);
		break;
	case SDL_CONTROLLER_BUTTON_Y:
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::YButton);
		break;
	}


}

Note::~Note()
{

}

bool Note::handleInput(Uint32 time, const SDL_Event& event) {

	return false;
}

void Note::update(Uint32 time) {
	double deltaTime = getGame()->deltaTime;
	position_.set(position_ + velocity_ * deltaTime);
}

