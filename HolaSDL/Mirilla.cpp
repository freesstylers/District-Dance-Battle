#include "Mirilla.h"



Mirilla::Mirilla(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Mira);
	controller = SDL_GameControllerOpen(0);
	framesPerSecond = 1;
	animation.currentFrame = 0;
}


Mirilla::~Mirilla()
{
}

bool Mirilla::handleInput(Uint32 time, const SDL_Event & event)
{
	return false;
}

bool Mirilla::handleInput(Uint32 time, const SDL_Event & event, Note* nota)
{
	if (event.type == SDL_CONTROLLERAXISMOTION)
	{
		/*if (event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTX)
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
		}*/

		if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX)
		{
			if (event.caxis.value > 10000)
				{
				velocity_.setX(event.caxis.value / 15000);
					//position_(position_.getX() + event.caxis.value / 2000);
					//cout << "Derecha? Stick I" << endl;
				}
			else if (event.caxis.value < -10000)
				{
				velocity_.setX(event.caxis.value / 15000);
				//cout << "Izquierda?  Stick I" << endl;
				}
			else
			{
				velocity_.setX(0);
			}
		}
		if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY)
		{ 
			if (event.caxis.value > 10000)
				{
				velocity_.setY(event.caxis.value / 15000);
				//cout << "Abajo?  Stick I" << endl;
				}
			else if (event.caxis.value < -10000)
				{
				velocity_.setY(event.caxis.value / 15000);
				//cout << "Arriba?  Stick I" << endl;
				}

			else
			{ 
				velocity_.setY(0);
			}
		}
	}

	else if (event.type == SDL_CONTROLLERBUTTONDOWN)
	{
		if (event.cbutton.button == nota->getKey() && superpuesto)
		{
			cout << "eres mazo bueno" << endl;
			nota->setActive(false);
		}
	}

	//cout << "Position: " << position_ << endl;

	
	return true;

	/*

	Movimiento stick -> Movimiento mirilla
	Check encima -> Pulsar -> "Destruir"
	*/
}

void Mirilla::update(Uint32 time)
{
	position_ = position_ + velocity_;
}
