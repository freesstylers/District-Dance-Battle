#include "BarrasHUD.h"

BarrasHUD::BarrasHUD(SDLGame* game, double width, double height, Vector2D pos, Vector2D vel):
	GameObject(game), texture(texture)
{
	//sprite de la barra
	//texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::);
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Bar);
}
void BarrasHUD::handleInput(Uint32 time, const SDL_Event& event) {


}
BarrasHUD::~BarrasHUD()
{

}

void BarrasHUD::update(Uint32 time)
{
	position_.set(position_ + velocity_);
}

void BarrasHUD::render(Uint32 time) {
	texture->render(getRect());
}
