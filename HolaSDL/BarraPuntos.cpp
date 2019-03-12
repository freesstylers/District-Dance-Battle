#include "BarraPuntos.h"

BarraPuntos::BarraPuntos(SDLGame* game, double width, double height, Vector2D pos, int numNotas, int maxBarra) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	numNotas_ = numNotas;
	maxHeight_ = game->getWindowHeight();
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Yellowbar);

	currentHeight = height;
	originalHeight = pos.getY();
}

bool BarraPuntos::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}

void BarraPuntos::avanza(int punt)
{
	double porcentaje;

	porcentaje = (maxHeight_ / numNotas_) * (1 / punt);

	currentHeight = currentHeight + porcentaje;

	setHeight(currentHeight);
	position_.setY(originalHeight - currentHeight);
}

void BarraPuntos::update(Uint32 time)
{
	//position_.set(position_);
}


BarraPuntos::~BarraPuntos()
{
}