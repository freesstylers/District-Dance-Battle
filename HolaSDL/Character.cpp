#include "Character.h"



Character::Character(SDLGame* game, double width, double height, Vector2D pos, int i) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
	timer = new TimerNoSingleton();
	firstAnim = i;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(i);
	
	isAnimationSyncedToMusic = true;
	animation.currentFrame = 1;
	if (i != Resources::PericoIdle)
	{
		switch (i)
		{
		case Resources::RobotIdle:
			secondAnim = Resources::RobotDance;
			break;
		case Resources::EminemciaIdle:
			secondAnim = Resources::EminemciaDance;
			break;
		case Resources::PapitoIdle:
			secondAnim = Resources::PapitoTwerk;
			break;
		}
	}
}


Character::~Character()
{
	delete timer;
}

bool Character::handleInput(Uint32 time, const SDL_Event& event) {

	return false;
}

void Character::update(Uint32 time) {
	timer->Update();
	if (timer->DeltaTime() > (rand()%(11)+10) && secondAnim != -1 && !dancing)
	{
		this->queueAnimationChange(secondAnim);
		timer->Reset();
		dancing = true;
	}
	else if (timer->DeltaTime() > (rand() % (11) + 10) && secondAnim != -1 && dancing)
	{
		this->queueAnimationChange(firstAnim);
		timer->Reset();
		dancing = false;
	}
}

