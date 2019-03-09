#include "Perico.h"



Perico::Perico(SDLGame* game, double width, double height, Vector2D pos) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));


	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::PericoIdle);

	framesPerSecond = 4;
	isAnimationSyncedToMusic = true;
	animation.currentFrame = 1;
}


Perico::~Perico()
{
}

bool Perico::handleInput(Uint32 time, const SDL_Event& event) {

	return false;
}

void Perico::update(Uint32 time) {


}

