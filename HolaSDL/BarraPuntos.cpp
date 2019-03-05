#include "BarraPuntos.h"

BarraPuntos::BarraPuntos(SDLGame* game, double width, double height, Vector2D pos, int numNotas, int maxBarra) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	numNotas_ = numNotas;
	maxBarra_ = maxBarra;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Bar);
}
bool BarraPuntos::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}
void BarraPuntos::avanza(int punt)
{
	double porcentaje;

	if (punt == 1)	
		porcentaje = maxBarra_ / numNotas_;
	else if(punt == 2)
		porcentaje = (maxBarra_ / numNotas_)*(2 / 3);
	else porcentaje = (maxBarra_ / numNotas_)*(1 / 3);

	setHeight(height_ + porcentaje);	
	position_.set(position_ - Vector2D(0, porcentaje));
}

void BarraPuntos::update(Uint32 time)
{
	//position_.set(position_);
}


BarraPuntos::~BarraPuntos()
{
}