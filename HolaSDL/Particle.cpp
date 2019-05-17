#include "Particle.h"
#include "sdl_includes.h"


Particle::Particle(Vector2D pos, Vector2D vel, int life,int h, int w, SDLGame* Game):GameObject(Game), life_(life)
{
	setHeight(h);
	setWidth(w);
	setPosition(pos);
	setVelocity(vel);
	endTime = SDL_GetTicks() + life;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Particles);
	isAnimationSyncedToMusic = true;
	animation.currentFrame = rand()%6;
}

void Particle::update(Uint32 time)
{
	setPosition(Vector2D(position_.getX() + velocity_.getX(), position_.getY() + velocity_.getY()));
}

bool Particle::isDead()
{
	return (SDL_GetTicks() >= endTime);
}
