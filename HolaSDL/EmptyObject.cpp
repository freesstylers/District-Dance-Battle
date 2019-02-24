#include "EmptyObject.h"

EmptyObject::EmptyObject(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Bar);
}
void EmptyObject::handleInput(Uint32 time, const SDL_Event& event) {


}
void EmptyObject::update(Uint32 time)
{
	position_.set(position_);
}
void EmptyObject::render(Uint32 time)
{
	texture->render(getRect());
}


EmptyObject::~EmptyObject()
{
}
