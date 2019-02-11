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
	texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Bird);
}

Flechas::~Flechas()
{

}

void Flechas::handleInput(Uint32 time, const SDL_Event& event) {


}

void Flechas::update(Uint32 time) {
	position_.set(position_ + velocity_);
	if (position_.getX() < getGame()->getWindowWidth())
	{
		//delete this;
	}
}

void Flechas::render(Uint32 time) {
	texture->render(getRect());
}

