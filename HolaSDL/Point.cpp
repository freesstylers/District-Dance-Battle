#include "Point.h"





Point::Point(SDLGame* game, double width, double height, Vector2D pos, SDL_GameController* contr, bool side) : GameObject(game), controller(contr), side_(side)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);

	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Point);
}

bool Point::handleInput(Uint32 time, const SDL_Event& event)
{
	if (event.type == SDL_CONTROLLERBUTTONDOWN)
	{
		if (side_)
		{
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
				SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
			{
				this->setAnimation(Resources::PointPushed);
			}
		}
		else
		{
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
				SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))
			{
				this->setAnimation(Resources::PointPushed);
			}
		}
	}
	else
	{
		if (side_)
		{
			if (!SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) && !SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) &&
				!SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) && !SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
			{
				this->setAnimation(Resources::Point);
			}
		}
		else
		{
			if (!SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && !SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) &&
				!SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) && !SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))
			{
				this->setAnimation(Resources::Point);
			}
		}
	}
	return false;
}
Point::~Point()
{
}
