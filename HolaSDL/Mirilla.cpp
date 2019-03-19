#include "Mirilla.h"



Mirilla::Mirilla(SDLGame* game, double width, double height, Vector2D pos): GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Mira);
}


Mirilla::~Mirilla()
{
}

bool Mirilla::handleInput(Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_CONTROLLERAXISMOTION)
	{
		if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX && event.caxis.value > 10000 || event.caxis.value < -10000)
		{
			position_.setX(position_.getX() + event.caxis.value / 32767);
			cout << "me muevo en X" << endl;
			cout << position_ << endl;
		}
		else if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY	&& event.caxis.value > 10000 || event.caxis.value < -10000)
		{
			position_.setY(position_.getY() + event.caxis.value / 32767);
			cout << "me muevo en Y" << endl;
			cout << position_ << endl;
		}
		/*
		else if (event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTX) && (event.caxis.value > 10000 || event.caxis.value < -10000)
		{}
		else if (event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTY) && (event.caxis.value > 10000	|| event.caxis.value < -10000)
			|| (event.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
			&& (event.caxis.value > 10000
				|| event.caxis.value < -10000)
			|| (event.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
			&& (event.caxis.value > 10000
				|| event.caxis.value < -10000))


		// Horizontal axis of left analog stick
		if (event.caxis.axis == 0)
		{
			position_.setX(position_.getX() + event.caxis.value / 32767);
			cout << "me muevo en X" << endl;
			cout << position_  << endl;

		}
		// Vertical axis of left analog stick
		if (event.caxis.axis == 1)
		{
			position_.setY(position_.getY() + event.caxis.value / 32767);
			cout << "me muevo en Y" << endl;
			cout << position_ << endl;

		}*/

		return true;
	}

	/*

	Movimiento stick -> Movimiento mirilla
	Check encima -> Pulsar -> "Destruir"
	*/
	return false;
}

void Mirilla::update(Uint32 time)
{

}
