#include "BarraPuntos.h"

BarraPuntos::BarraPuntos(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Bar);
}
bool BarraPuntos::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}
void BarraPuntos::avanza(int punt)
{
	setHeight(height_ + punt);	
}

void BarraPuntos::update(Uint32 time)
{
	//position_.set(position_);
}


BarraPuntos::~BarraPuntos()
{
}