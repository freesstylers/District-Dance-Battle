#include "Point.h"


Point::Point(SDLGame* game, double width, double height, Vector2D pos, SDL_GameController* contr, bool side, int player_) : GameObject(game), controller(contr), side_(side)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);

	if (player_ == 0)
	{
		controllerMode = game->getP1Controller();
	}
	else if (player_ == 1)
	{
		controllerMode = game->getP2Controller();
	}
	
	if (controllerMode != 2)
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Point);
	else
		animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::KeyPoint);
}

//Change the point animation when some button is pushed
bool Point::handleInput(Uint32 time, const SDL_Event& event)
{
	if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN)
	{
		if (side_)
		{
			if (controllerMode != 2) //Mando
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
					SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
					this->setAnimation(Resources::PointPushed);
			}
			else
			{ 
				if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_w)
				this->setAnimation(Resources::KeyPointPushed);
			}
		}
		else
		{
			if (controllerMode != 2)
			{
				if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) ||
					SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))
					this->setAnimation(Resources::PointPushed);
			}
			else
			{
				if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_UP)
				this->setAnimation(Resources::KeyPointPushed);
			}
		}
	}
	else
	{
		if (side_)
		{
			if (controllerMode != 2)
			{
				if (!SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) && !SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) &&
					!SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) && !SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
					this->setAnimation(Resources::Point);
			}
			else
			{
				if (!(event.key.keysym.sym == SDLK_a) && !(event.key.keysym.sym == SDLK_d) && !(event.key.keysym.sym == SDLK_s) && !(event.key.keysym.sym == SDLK_w))
					this->setAnimation(Resources::KeyPoint);
			}
		}
		else
		{
			if (controllerMode != 2)
			{
				if (!SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && !SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) &&
					!SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) && !SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y))
					this->setAnimation(Resources::Point);
			}
			else
			{
				if (!(event.key.keysym.sym == SDLK_LEFT) && !(event.key.keysym.sym == SDLK_RIGHT) && !(event.key.keysym.sym == SDLK_DOWN) && !(event.key.keysym.sym == SDLK_UP))
					this->setAnimation(Resources::KeyPoint);
			}
		}
	}
	return false;
}
Point::~Point()
{
}
