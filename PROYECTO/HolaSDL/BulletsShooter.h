#pragma once

#include "Bullet.h"
#include "GameObject.h"

/*
 *
 */
class BulletsShooter: public GameObject {
public:
	BulletsShooter(SDLGame* game);
	virtual ~BulletsShooter();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual void addBullet(Vector2D pos, Vector2D vel);
private:
	Bullet* getUnusedBullet();
	static int const MAX_BULLETS=100;
	Bullet bullets_[MAX_BULLETS];

};

