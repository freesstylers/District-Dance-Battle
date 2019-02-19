#include "Flechas.h"


Flechas::Flechas()
{

}
Flechas::Flechas(SDL_Keycode key, SDLGame* game, double width, double height, Vector2D pos, Vector2D vel) :
	GameObject(game), texture(texture), key(key)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	switch (key) {
	case SDLK_LEFT:
		texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaLeft);
		break;
	case SDLK_RIGHT:
		texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaRight);
		break;
	case SDLK_UP:
		texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaUp);
		break;
	case SDLK_DOWN:
		texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::FlechaDown);
		break;
	}
}

Flechas::~Flechas()
{

}

void Flechas::handleInput(Uint32 time, const SDL_Event& event) {
	
}

void Flechas::update(Uint32 time) {
	position_.set(position_ + velocity_);
}

void Flechas::render(Uint32 time) {
	texture->render(getRect());
}

