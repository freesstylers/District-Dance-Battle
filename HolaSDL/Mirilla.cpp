#include "Mirilla.h"



Mirilla::Mirilla(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Mira);
	controller = SDL_GameControllerOpen(0);
}


Mirilla::~Mirilla()
{
}

bool Mirilla::handleInput(Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_CONTROLLERAXISMOTION)
	{
		if (event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTX)
		{
			if (event.caxis.value > 10000)
				{
					position_.setX(position_.getX() + event.caxis.value/20000);
					cout << "Derecha? Stick D" << endl;
				}
			if (event.caxis.value < -10000)
				{
					position_.setX(position_.getX() + event.caxis.value / 20000);
					cout << "Izquierda? Stick D" << endl;
				}
		}
		if (event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTY)
		{
			if (event.caxis.value > 10000)
				{
					position_.setY(position_.getY() + event.caxis.value / 20000);
					cout << "Abajo? Stick D" << endl;
				}
			if (event.caxis.value < -10000)
				{
					position_.setY(position_.getY() + event.caxis.value / 20000);
					cout << "Arriba? Stick D" << endl;
				}
		}

		if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX)
		{
			if (event.caxis.value > 10000)
				{
					position_.setX(position_.getX() + event.caxis.value / 20000);
					cout << "Derecha? Stick I" << endl;
				}
			if (event.caxis.value < -10000)
				{
					position_.setX(position_.getX() + event.caxis.value / 20000);
					cout << "Izquierda?  Stick I" << endl;
				}
		}
		if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY)
		{ 
			if (event.caxis.value > 10000)
				{
					position_.setY(position_.getY() + event.caxis.value / 20000);
					cout << "Abajo?  Stick I" << endl;
				}
			if (event.caxis.value < -10000)
				{
					position_.setY(position_.getY() + event.caxis.value / 20000);
					cout << "Arriba?  Stick I" << endl;
				}
		}
	}

	cout << "Position: " << position_ << endl;

	
	return true;

	/*

	Movimiento stick -> Movimiento mirilla
	Check encima -> Pulsar -> "Destruir"
	*/
}

void Mirilla::update(Uint32 time)
{

}
