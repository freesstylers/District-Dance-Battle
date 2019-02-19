#include "EmptyObject.h"

EmptyObject::EmptyObject(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	//texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::);
}

void EmptyObject::render(Uint32 time)
{
	texture->render(getRect());
}
void EmptyObject::handleInput(Uint32 time, const SDL_Event& event) {


}
EmptyObject::~EmptyObject()
{
}
